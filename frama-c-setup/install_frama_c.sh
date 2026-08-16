#!/usr/bin/env bash
set -Eeuo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"
PROJECT_ROOT="$(cd -- "${SCRIPT_DIR}/.." && pwd -P)"
OPAM_ROOT="${SCRIPT_DIR}/.opam"
BIN_DIR="${SCRIPT_DIR}/bin"
SWITCH_NAME="${SCF_FRAMA_C_SWITCH:-scf-frama-c}"
OCAML_VERSION="${SCF_OCAML_VERSION:-4.14.2}"
LOG_FILE="${SCRIPT_DIR}/install.log"
CURRENT_STAGE="startup"

# Conda or a previously activated OPAM environment may export a switch name
# that does not exist inside this project's private OPAM root.
unset OPAMSWITCH OPAM_SWITCH_PREFIX
unset CAML_LD_LIBRARY_PATH OCAML_TOPLEVEL_PATH OCAMLLIB OCAML_PATH OCAMLFIND_CONF

export OPAMROOT="${OPAM_ROOT}"
export OPAMNOENVNOTICE=true
export OPAMASSUMEDEPEXTS=true

: > "${LOG_FILE}"
exec > >(tee -a "${LOG_FILE}") 2>&1

on_error() {
  local status=$?
  trap - ERR
  echo
  echo "ERROR: Project-local Frama-C setup failed during: ${CURRENT_STAGE}" >&2
  echo "Full log: ${LOG_FILE}" >&2
  exit "${status}"
}
trap on_error ERR

CURRENT_STAGE="checking the active Conda environment"
if ! command -v opam >/dev/null 2>&1; then
  echo "ERROR: opam is unavailable in the active environment." >&2
  echo "Activate the Conda environment supplied by this project, then run:" >&2
  echo "  bash ./frama-c-setup/install_frama_c.sh" >&2
  exit 2
fi

for tool in make m4 pkg-config; do
  if ! command -v "${tool}" >/dev/null 2>&1; then
    echo "ERROR: required build tool is unavailable: ${tool}" >&2
    echo "Update and activate the project Conda environment first." >&2
    exit 2
  fi
done

if ! pkg-config --exists zlib; then
  echo "ERROR: zlib development metadata is missing from the active environment." >&2
  echo "Run: conda env update -f environment.yml --prune" >&2
  echo "Then reactivate the environment and rerun this installer." >&2
  exit 2
fi

for compiler in "${CC:-cc}" "${CXX:-c++}"; do
  compiler_command="${compiler%% *}"
  if ! command -v "${compiler_command}" >/dev/null 2>&1; then
    echo "ERROR: required compiler is unavailable: ${compiler_command}" >&2
    echo "Update and activate the project Conda environment first." >&2
    exit 2
  fi
done

mkdir -p "${OPAM_ROOT}" "${BIN_DIR}"

if [[ ! -f "${OPAM_ROOT}/config" ]]; then
  CURRENT_STAGE="initializing the project-local OPAM root"
  echo "Initializing the project-local OPAM root: ${OPAM_ROOT}"
  opam init --root="${OPAM_ROOT}" \
    --bare \
    --no-setup \
    --disable-sandboxing \
    --yes
fi

CURRENT_STAGE="updating the project-local OPAM repository"
echo "Updating the project-local OPAM repository..."
opam update --root="${OPAM_ROOT}" --yes

CURRENT_STAGE="creating the project-local OCaml switch"
if ! opam switch list --root="${OPAM_ROOT}" --short \
  | grep -Fxq "${SWITCH_NAME}"; then
  echo "Creating the project-local OPAM switch ${SWITCH_NAME}..."
  opam switch create \
    --root="${OPAM_ROOT}" \
    "${SWITCH_NAME}" "ocaml-base-compiler.${OCAML_VERSION}" \
    --yes
fi

CURRENT_STAGE="installing Frama-C and Alt-Ergo"
echo "Installing Frama-C and Alt-Ergo inside ${PROJECT_ROOT}..."
opam install --root="${OPAM_ROOT}" \
  --switch="${SWITCH_NAME}" \
  --yes \
  frama-c alt-ergo

CURRENT_STAGE="creating project-local launchers"
write_wrapper() {
  local program="$1"
  local target="${BIN_DIR}/${program}"
  {
    printf '%s\n' '#!/usr/bin/env bash' 'set -Eeuo pipefail'
    printf '%s\n' 'SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"'
    printf '%s\n' 'SETUP_DIR="$(cd -- "${SCRIPT_DIR}/.." && pwd -P)"'
    printf '%s\n' 'OPAM_ROOT="${SETUP_DIR}/.opam"'
    printf 'SWITCH_NAME=%q\n' "${SWITCH_NAME}"
    printf '%s\n' 'unset OPAMSWITCH OPAM_SWITCH_PREFIX'
    printf '%s\n' 'unset CAML_LD_LIBRARY_PATH OCAML_TOPLEVEL_PATH OCAMLLIB OCAML_PATH OCAMLFIND_CONF'
    printf '%s\n' 'export OPAMROOT="${OPAM_ROOT}"' 'export OPAMNOENVNOTICE=true'
    printf '%s\n' 'if ! command -v opam >/dev/null 2>&1; then'
    printf '%s\n' '  echo "ERROR: activate the project Conda environment before running Frama-C." >&2'
    printf '%s\n' '  exit 127' 'fi'
    printf 'exec opam exec --root="${OPAM_ROOT}" --switch="${SWITCH_NAME}" -- %q "$@"\n' "${program}"
  } > "${target}"
  chmod 0755 "${target}"
}

write_wrapper frama-c
write_wrapper alt-ergo

CURRENT_STAGE="verifying the project-local installation"
echo "Project-local Frama-C installation completed."
echo "No system directory or shell profile was modified."
"${BIN_DIR}/frama-c" --version
echo
echo "Detected WP provers:"
"${BIN_DIR}/frama-c" -wp-detect || true
echo
echo "Run from the project root: python ./check_environment.py"
