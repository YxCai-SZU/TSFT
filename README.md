# TSFT

TSFT implements Two-Stage Fine-Tuning for ACSL specification generation. It includes C/ACSL preprocessing, semantics-preserving candidate generation, LoRA/QLoRA training, and Frama-C/WP evaluation.

## Public artifacts

| Artifact | Location |
|---|---|
| Source code | This repository |
| Qwen3.5-4B base model | [Qwen/Qwen3.5-4B](https://huggingface.co/Qwen/Qwen3.5-4B) |
| Qwen3.5-9B base model | [Qwen/Qwen3.5-9B](https://huggingface.co/Qwen/Qwen3.5-9B) |
| TSFT adapters | [Qwen3.5-4B-TSFT](https://huggingface.co/EJzzzzz/ACSL-TSFT-Qwen3.5-4B-Adapter/tree/main) |
| TSFT adapters | [Qwen3.5-9B-TSFT](https://huggingface.co/EJzzzzz/ACSL-TSFT-Qwen3.5-9B-Adapter/tree/main) | 

The repository does not contain base-model weights or trained adapters. You can download them from the above given urls.

## Installation

The supported environment uses Python 3.11 and CUDA 12.4.

```bash
conda env create -f environment.yml
conda activate tsft-qwen35-4b
```

Install the project-local Frama-C/WP environment:

```bash
bash ./frama-c-setup/install_frama_c.sh
```

Download the configured base model:

```bash
python ./download_model.py
```

`download_model.py` reads `model.hub_id`, `model.revision`, and `model.base_model` from `configs/train.yaml`. Update those three fields together when switching to the 9B model.

## Data preparation

Place labeled C/ACSL sources under `trainingdata_raw/`, then generate the JSON training records:

```bash
python ./generate_training_data.py --inputdir ./trainingdata_raw --outputdir ./trainingData
```

The command and its arguments are unchanged from the original implementation. Each run creates `trainingData_N.json` in the output directory.

Optional preprocessing tools:

```bash
# Generate Clang call-graph artifacts.
python ./generate_callgraph.py ./trainingdata_raw -o ./ClangOutput

# Remove expandable ACSL background definitions and retain WP-verified files.
python ./remove_acsl_background.py INPUT_DIR OUTPUT_DIR --workers 8
```

Use `python SCRIPT.py --help` for the complete option list.

## Training

`configs/train.yaml` preserves the original launcher defaults. 

```yaml
training:
  loss_schedule:
    stage1:
      name: ground_truth_ce
      ratio: 0.6
    stage2:
      name: nearest_equivalent_ce
      ratio: 0.4
```

Check the environment and start distributed training on all visible GPUs:

```bash
python ./check_environment.py
python ./run_train.py
```

`run_train.py` continues to read `configs/train.yaml`, preserving the original launch behavior. To run the paper configuration without replacing that file, use the lower-level entry point:

```bash
torchrun --standalone --nproc_per_node=2 \
  -m tsft.train --config ./configs/paper-tsft-4b.yaml
```

## Held-out-set evaluation

Set `evaluation.adapter_dir` in `configs/train.yaml` to the trained adapter, then run:

```bash
python ./testsetEval.py
```

The evaluator reports output-format compliance, Frama-C parse success, target-type correctness, WP verification results, and ground-truth loss for the held-out split.

## Project-level evaluation

The project-level evaluator constructs a bottom-up function/loop task sequence, generates one ACSL contract at a time, and keeps a generated contract only after it passes Frama-C/WP. The base model must already exist locally; `--adapterdir` is optional when evaluating the base model.

Evaluate one C file with `evaluation_pipeline.py`:

```bash
python ./evaluation_pipeline.py \
  --file ./evaluation_datasets/SyGuS/1.c \
  --modeldir ./model/Qwen3.5-4B \
  --adapterdir ./training_output/best_checkpoint \
  --outputdir ./evaluation_output/single \
  --attempts 5
```

The command writes `task_graph.json`, the generated and verified artifacts under `StepN/attempt_NN/`, the progressively annotated temporary C file, and the compact `final_result.json` under `OUTPUT_DIR/<source-name>/`. Omit `--adapterdir` to evaluate the base model. `--attempts` and `--max-attempts-per-task` are equivalent.

Evaluate every `.c` file below a directory with `multifile_pipline.py`:

```bash
python ./multifile_pipline.py \
  --file ./evaluation_datasets/SyGuS \
  --modeldir ./model/Qwen3.5-4B \
  --adapterdir ./training_output/best_checkpoint \
  --outputdir ./evaluation_output/SyGuS \
  --attempts 5
```

The batch command searches `--file` recursively. It preserves each source file's relative directory in `--outputdir`, runs the same single-file workflow, and writes aggregate pass rates, token counts, and solve times to `batch_result.json`. The historical filename `multifile_pipline.py` is retained for command compatibility.

Both commands use the project-local Frama-C launcher when available and otherwise use `frama-c` from `PATH`. Common overrides include `--frama-c-executable`, `--frama-c-provers`, `--frama-c-wp-timeout`, `--max-input-tokens`, `--max-new-tokens`, and `--disable-thinking`. Run either script with `--help` for the complete unchanged option list.
