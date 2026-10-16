============================================================
        Competitive Programming & Vim Cheat Sheet
============================================================


[1] Terminal Commands
------------------------------------------------------------

# Create a new file
vim file.cpp

# Edit configuration
vim ~/_vimrc

# Compile
g++ file.cpp -o file.exe

# Run (Linux / WSL)
./file.exe


[2] Vim Basic Configuration
------------------------------------------------------------

Put the following content into ~/.vimrc or ~/_vimrc:

" --- 1. Basic Display and Editing ---
set tabstop=4        " Set Tab width to 4 spaces
set shiftwidth=4     " Set indentation width to 4 spaces
set expandtab        " Insert spaces instead of actual Tab character when pressing Tab
set number           " Show current line number
set relativenumber   " Show relative line numbers for easier movement commands
set nowrap           " Disable automatic line wrapping, require horizontal scrolling for long lines
set autoindent       " Copy indent from the previous line when starting a new line
set smartindent      " Automatically adjust indentation based on code structure (e.g., braces)

" --- 2. Search and Matching Highlight ---
set incsearch        " Jump to match dynamically while typing search keywords
set hlsearch         " Highlight all search matches
set showmatch        " Briefly jump to the matching opening bracket when typing a closing bracket

" --- 3. System Clipboard (Linux may require xclip / xsel) ---
set clipboard=unnamedplus " Use system clipboard for copy and paste between Vim and other programs

" --- 4. Auto Compile and Run C++ on F5 ---
autocmd FileType cpp nnoremap <F5> :w <Bar> !g++ -O2 -std=c++17 % -o %< && ./%<<CR>

" --- 5. Auto-pair Brackets ---
inoremap ( ()<Left> " Auto-complete parentheses and place cursor in the middle
inoremap [ []<Left> " Auto-complete brackets and place cursor in the middle
inoremap { {}<Left> " Auto-complete braces and place cursor in the middle


[3] Vim Keybindings Cheat Sheet
============================================================

I. Mode Switching
------------------------------------------------------------

Key                  Function
------------------------------------------------------------
Esc                  Return to Normal Mode
i                    Enter Insert Mode, insert before cursor
a                    Enter Insert Mode, insert after cursor
v                    Enter Visual Mode, select characters
V                    Enter Visual Mode, select entire lines
:                    Enter Command-line Mode


II. Cursor Movement
------------------------------------------------------------

Key                  Function
------------------------------------------------------------
h                    Move cursor left
j                    Move cursor down
k                    Move cursor up
l                    Move cursor right
w                    Move to the beginning of the next word
b                    Move to the beginning of the previous word
0                    Move to the beginning of the current line
$                    Move to the end of the current line
gg                   Move to the top of the file
G                    Move to the end of the file


III. Basic Editing
------------------------------------------------------------

Key                  Function
------------------------------------------------------------
x                    Delete character under cursor
u                    Undo
Ctrl + r             Redo
yy                   Copy (yank) current line
p                    Paste after cursor
dd                   Delete current line
dw                   Delete from cursor to the next word boundary
d$                   Delete from cursor to the end of the line
ciw                  Change current word under cursor
                     (delete word and enter insert mode)


IV. Files and Commands
------------------------------------------------------------

Command              Function
------------------------------------------------------------
:w                   Save file
:q                   Quit
:q!                  Force quit without saving
:wq                  Save and quit
:x                   Save and quit if modified
:%s/old/new/g        Substitute all occurrences of "old" with "new" in the file


============================================================
                      Usage Notes
============================================================

1. Key operations are performed in Normal Mode by default; use Insert Mode for typing text.

2. :%s/old/new/g replaces all matches in the file.
   Remove the trailing 'g' if you only want to replace the first match per line.

3. The F5 shortcut saves the file first, then compiles and runs using C++17.
   If compilation fails, && prevents execution.

4. set clipboard=unnamedplus requires Vim compiled with clipboard support;
   Linux environments may also require xclip or xsel.

5. If using native Windows, execution command might need to be:
   .\file.exe