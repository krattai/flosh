
function nocommand
        if commandline | sgrep -qe "add-key\|backup\|client-keys\|clients\|diff\|dump-repo\|force-lock\|forget\|fsck\|generations\|genids\|list-keys\|list-toplevels\|ls\|mount\|nagios-last-backup-age\|remove-client\|remove-key\|restore\|verify"
                return 1
        end
        return 0
end

complete --command obnam --no-files --condition nocommand --arguments 'add-key' --description 'Adds an encryption key to the repository'
complete --command obnam            --condition nocommand --arguments 'backup' --description 'Makes a new backup'
complete --command obnam --no-files --condition nocommand --arguments 'client-keys' --description 'Lists the keys associated with each client'
complete --command obnam --no-files --condition nocommand --arguments 'clients' --description 'Lists the clients in the repository'
complete --command obnam --no-files --condition nocommand --arguments 'diff' --description 'Compares two generations'
complete --command obnam --no-files --condition nocommand --arguments 'dump-repo' --description 'Dumps the repository'
complete --command obnam --no-files --condition nocommand --arguments 'force-lock' --description 'Removes a lock file for a client'
complete --command obnam --no-files --condition nocommand --arguments 'forget' --description 'Removes backup generations'
complete --command obnam --no-files --condition nocommand --arguments 'fsck' --description 'Checks the consistency of the repository'
complete --command obnam --no-files --condition nocommand --arguments 'generations' --description 'Lists every backup generation'
complete --command obnam --no-files --condition nocommand --arguments 'genids' --description 'Lists the identifier for every generation'
complete --command obnam --no-files --condition nocommand --arguments 'list-keys' --description 'Lists the keys'
complete --command obnam --no-files --condition nocommand --arguments 'list-toplevels' --description 'Lists the toplevel keys'
complete --command obnam --no-files --condition nocommand --arguments 'ls' --description 'Lists the contents of a given generation'
complete --command obnam --no-files --condition nocommand --arguments 'mount' --description 'Makes the repository available via FUSE'
complete --command obnam --no-files --condition nocommand --arguments 'nagios-last-backup-age' --description 'Check if a backup age exceeds a threshold'
complete --command obnam --no-files --condition nocommand --arguments 'remove-client' --description 'Removes a client from the repository'
complete --command obnam --no-files --condition nocommand --arguments 'remove-key' --description 'Removes a key from the repository'
complete --command obnam --no-files --condition nocommand --arguments 'restore' --description 'Restore files from the repository'
complete --command obnam --no-files --condition nocommand --arguments 'verify' --description 'Verifies files in the repository'

complete --command obnam --no-files --long-option always-restore-setuid --description 'Restore setuid/setgid bits in restored files'
complete --command obnam --no-files --long-option no-always-restore-setuid --description 'Do not restore setuid/setgid bits in restored files'
complete --command obnam --no-files --long-option client-name --arguments '(hostname)' --description 'Name of client'
complete --command obnam --no-files --long-option compress-with --arguments 'none deflate' --description 'Compress repository with'
complete --command obnam --no-files --long-option critical-age --description 'For --nagios-last-backup-age: maximum age'
complete --command obnam --no-files --long-option dump-repo-file-metadata --description 'Dump metadata about files'
complete --command obnam --no-files --long-option no-dump-repo-file-metadata --description 'Do not dump metadata about files'
complete --command obnam --no-files --long-option generate-manpage --description 'Generate man page'
complete --command obnam --no-files --long-option generation --description 'Which generation to restore'
complete --command obnam --no-files --short-option h --long-option help --description 'Show this help message and exit'
complete --command obnam --no-files --long-option keep --description 'Policy for what generations to keep when forgetting.'
complete --command obnam --no-files --long-option lock-timeout --description 'Wait TIMEOUT seconds for an existing lock'
complete --command obnam --long-option output --description 'Write output to FILE instead of STDOUT'
complete --command obnam --no-files --long-option pretend --long-option dry-run --long-option no-act --description 'Do not actually change anything'
complete --command obnam --no-files --long-option no-pretend --long-option no-dry-run --long-option no-no-act --description 'Actually commit changes'
complete --command obnam --no-files --long-option quiet --description 'Show only errors, no progress updates'
complete --command obnam --no-files --long-option no-quiet --description 'Show errors and progress updates'
complete --command obnam --short-option r --long-option repository --description 'Name of backup repository'
complete --command obnam --long-option root --description 'What to backup'
complete --command obnam --no-files --long-option testing-fail-matching --description 'Simulate failures for files that match REGEXP'
complete --command obnam --long-option to --description 'Where to restore / mount to'
complete --command obnam --long-option trace --description 'FILENAME pattern for trace debugging'
complete --command obnam --no-files --long-option verbose --description 'Be more verbose'
complete --command obnam --no-files --long-option no-verbose --description 'Do not be verbose'
complete --command obnam --no-files --long-option verify-randomly --description 'Verify N files randomly from the backup'
complete --command obnam --no-files --long-option version --description 'Show version number and exit'
complete --command obnam --long-option warn-age --description 'For nagios-last-backup-age: maximum age'
complete --command obnam --no-files --long-option checkpoint --description 'Make a checkpoint after a given SIZE'
complete --command obnam --no-files --long-option deduplicate --arguments 'fatalist never verify' --description 'Deduplicate mode'
complete --command obnam --long-option exclude --description 'REGEXP for pathnames to exclude'
complete --command obnam --no-files --long-option exclude-caches --description 'Exclude directories tagged as cache'
complete --command obnam --no-files --long-option no-exclude-caches --description 'Include directories tagged as cache'
complete --command obnam --long-option exclude-from --description 'Read exclude patterns from FILE.'
complete --command obnam --no-files --long-option leave-checkpoints --description 'Leave checkpoint generations at the end of backup'
complete --command obnam --no-files --long-option no-leave-checkpoints --description 'Omit checkpoint generations at the end of backup'
complete --command obnam --no-files --long-option one-file-system --description 'Do not follow mount points'
complete --command obnam --no-files --long-option no-one-file-system --description 'Follow mount points'
complete --command obnam --no-files --long-option small-files-in-btree --description 'Put small files directly into the B-tree'
complete --command obnam --no-files --long-option no-small-files-in-btree --description 'No not put small files into the B-tree'
complete --command obnam --long-option config --description 'Add FILE to config files'
complete --command obnam --no-files --long-option dump-config --description 'Write out the current configuration'
complete --command obnam --no-files --long-option dump-setting-names --description 'Write out setting names'
complete --command obnam --no-files --long-option help-all --description 'Show all options'
complete --command obnam --no-files --long-option list-config-files --description 'List config files'
complete --command obnam --no-files --long-option no-default-configs --description 'Clear list of configuration files to read'
complete --command obnam --no-files --long-option encrypt-with --description 'PGP key with which to encrypt'
complete --command obnam --no-files --long-option key-details --description 'Show additional user IDs'
complete --command obnam --no-files --long-option no-key-details --description 'Do not show additional user IDs'
complete --command obnam --no-files --long-option keyid --description 'PGP key id'
complete --command obnam --no-files --long-option symmetric-key-bits --description 'Size of symmetric key'
complete --command obnam --no-files --long-option weak-random --description 'Use /dev/urandom instead of /dev/random'
complete --command obnam --no-files --long-option no-weak-random --description 'Use default /dev/random'

complete --command obnam --no-files --long-option fsck-fix --description 'fsck should try to fix problems'
complete --command obnam --no-files --long-option no-fsck-fix --description 'fsck should not try to fix problems'
complete --command obnam --no-files --long-option fsck-ignore-chunks --description 'Ignore chunks when checking integrity'
complete --command obnam --no-files --long-option no-fsck-ignore-chunks --description 'Check chunks when checking integrity'
complete --command obnam --no-files --long-option fsck-ignore-client --description 'Do not check data for cient NAME.'
complete --command obnam --no-files --long-option fsck-last-generation-only --description 'Check only the last generation'
complete --command obnam --no-files --long-option no-fsck-last-generation-only --description 'Check all generations'
complete --command obnam --no-files --long-option fsck-skip-dirs --description 'Do not check directories'
complete --command obnam --no-files --long-option no-fsck-skip-dirs --description 'Check directories'
complete --command obnam --no-files --long-option fsck-skip-files --description 'Do not check files'
complete --command obnam --no-files --long-option no-fsck-skip-files --description 'Check files'
complete --command obnam --no-files --long-option fsck-skip-generations --description 'Do not check any generations'
complete --command obnam --no-files --long-option no-fsck-skip-generations --description 'Check all generations'
complete --command obnam --no-files --long-option fsck-skip-per-client-b-trees --description 'Do not check per-client B-trees'
complete --command obnam --no-files --long-option no-fsck-skip-per-client-b-trees --description 'Check per-client B-trees'
complete --command obnam --no-files --long-option fsck-skip-shared-b-trees --description 'Do not check shared B-trees'
complete --command obnam --no-files --long-option no-fsck-skip-shared-b-trees --description 'Check shared B-trees'

complete --command obnam --long-option log --arguments 'syslog' --description 'Write log to FILE or syslog'
complete --command obnam --no-files --long-option log-keep --description 'Keep last N logs (10)'
complete --command obnam --no-files --long-option log-level --arguments 'debug info warning error critical fatal' --description 'Log at LEVEL'
complete --command obnam --no-files --long-option log-max --description 'Rotate logs larger than SIZE'
complete --command obnam --no-files --long-option log-mode --description 'Set permissions of logfiles to MODE'
complete --command obnam --no-files --long-option fuse-opt --description 'Options to pass to FUSE'
complete --command obnam --no-files --long-option dump-memory-profile --arguments 'none simple meliae heapy' --description 'Make memory profiling dumps using METHOD'
complete --command obnam --no-files --long-option memory-dump-interval --description 'Make memory profiling dumps at SECONDS'
complete --command obnam --no-files --long-option chunk-size --description 'Size of chunks of file data'
complete --command obnam --no-files --long-option chunkids-per-group --description 'Encode NUM chunk ids per group'
complete --command obnam --no-files --long-option idpath-bits --description 'Chunk id level size'
complete --command obnam --no-files --long-option idpath-depth --description 'Depth of chunk id mapping'
complete --command obnam --no-files --long-option idpath-skip --description 'Chunk id mapping lowest bits skip'
complete --command obnam --no-files --long-option lru-size --description 'Size of LRU cache for B-tree nodes'
complete --command obnam --no-files --long-option node-size --description 'Size of B-tree nodes on disk'
complete --command obnam --no-files --long-option upload-queue-size --description 'Length of upload queue for B-tree nodes'
complete --command obnam --no-files --long-option pure-paramiko --description 'Use only paramiko, no openssh'
complete --command obnam --no-files --long-option no-pure-paramiko --description 'Use openssh if available'
complete --command obnam --long-option ssh-command --description 'Executable to be used instead of "ssh"'
complete --command obnam --no-files --long-option ssh-host-keys-check --arguments 'no yes ask ssh-config' --description 'ssh host key check'
complete --command obnam --long-option ssh-key --description 'Use FILENAME as the ssh RSA key'
complete --command obnam --long-option ssh-known-hosts --arguments '~/.ssh/known_hosts' --description 'FILENAME of the known_hosts file'
