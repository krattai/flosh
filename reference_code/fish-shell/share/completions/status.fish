
complete -c status -s h -l help --description "Display help and exit"
complete -c status -l is-command-substitution --description "Test if a command substitution is currently evaluated"
complete -c status -l is-block --description "Test if a code block is currently evaluated"
complete -c status -l is-interactive --description "Test if this is an interactive shell"
complete -c status -l is-login --description "Test if this is a login shell"
complete -c status -l is-full-job-control --description "Test if all new jobs are put under job control"
complete -c status -l is-interactive-job-control --description "Test if only interactive new jobs are put under job control"
complete -c status -l is-no-job-control --description "Test if new jobs are never put under job control"
complete -c status -s j -l job-control -xa "full interactive none" --description "Set which jobs are out under job control"
complete -c status -s t -l print-stack-trace --description "Print a list of all function calls leading up to running the current command"
complete -c status -s f -l current-filename --description "Print the filename of the currently running script"
complete -c status -s n -l current-line-number --description "Print the line number of the currently running script"
complete -c status -s t -l print-stack-trace --description "Prints a trace of all function calls on the stack"