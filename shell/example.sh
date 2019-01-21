#!/usr/bin/env bash
: <<"eof"

eof
set -o errexit
set -o nounset
set -o pipefail
readonly SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
main() {
    # your code goes here...
}
main "${@}"