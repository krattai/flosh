#
# Command specific completions for the wesnoth command.
# These completions where generated from the commands
# man page by the make_completions.py script, and
# have been hand edited since.
#

complete -c wesnoth -l bpp --description 'Number sets BitsPerPixel value'
complete -c wesnoth -l compress --description '<infile> <outfile> compresses a savefile (infile) that is in text WML format into binary WML format (outfile)'
complete -c wesnoth -s d -l debug --description 'Shows extra debugging information and enables additional command mode options in-game'
complete -c wesnoth -l decompress --description '<infile> <outfile> decompresses a savefile (infile) that is in binary WML format into text WML format (outfile)'
complete -c wesnoth -s f -l fullscreen --description 'Runs the game in full screen mode'
complete -c wesnoth -l fps --description 'Displays the number of frames per second the game is currently running at, in a corner of the screen'
complete -c wesnoth -s h -l help --description 'Displays a summary of command line options to standard output, and exits'
complete -c wesnoth -l load --description 'Savegame loads the file savegame from the standard save game directory'
complete -c wesnoth -l log-error -l log-warning -l log-info --description 'Set the severity level of debugging domains'
complete -c wesnoth -l multiplayer --description 'Runs a multiplayer game'
complete -c wesnoth -l nocache --description 'Disables caching of game data'
complete -c wesnoth -l nosound --description 'Runs the game without sounds and music'
complete -c wesnoth -l path --description 'Prints the name of the game data directory and exits'
complete -c wesnoth -s r -l resolution --description 'XxY sets the screen resolution'
complete -c wesnoth -s t -l test --description 'Runs the game in a small test scenario'
complete -c wesnoth -s v -l version --description 'Shows the version number and exits'
complete -c wesnoth -s w -l windowed --description 'Runs the game in windowed mode'
complete -c wesnoth -l no-delay --description 'Runs the game without any delays for graphic benchmarking'
complete -c wesnoth -l exit-at-end --description 'Exits once the scenario is over, without displaying victory/defeat dialog which requires the user to click OK'
#complete -c wesnoth -l algorithm<number> --description 'Selects a non-standard algorithm to be used by the AI controller for this side'
#complete -c wesnoth -l controller<number> --description 'Selects the controller for this side'
complete -c wesnoth -l era --description 'Use this option to play in the selected era instead of the "Default" era'
complete -c wesnoth -l nogui --description 'Runs the game without the GUI'
complete -c wesnoth -l parm<number> --description 'Sets additional parameters for this side'
complete -c wesnoth -l scenario --description 'Selects a multiplayer scenario'
complete -c wesnoth -l side<number> --description 'Selects a faction of the current era for this side'
complete -c wesnoth -l turns --description 'Sets the number of turns for the chosen scenario'
