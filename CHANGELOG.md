## [Unreleased]
### Added
### Changed
### Fixed

* Fix pitch for OpenAL

## [1.4.1] - 2021-01-02
### Added

* Savestates can be compressed
* Middle button to reset controller axis to 0
* Hook getpid() used for prng seeding
* Option to use a forked process to save state
* Accept hotkeys when input editor and controller inputs window have focus (#349)
* Store input column order from input editor in movies (#328)
* Implement SDL_Lock/UnlockAudio (#358)
* Implement ram watch saving/loading
* Pointer scanning can start from any file-mapped memory
* Prevent SDL from creating custom cursors
* Non-blocking ALSA mode (#361)
* Add a non-interactive mode
* Support window title change from XChangeProperty()
* Add VDPAU rendering
* Add missing fields in Xlib input events (#365)
* Add special case for dlsym(RTLD_NEXT) (#82)
* Remove input events from window event masks (#365)
* Add basic EGL support
* Add commit version and date to window title
* Add cubeb support
* Implement ALSA underrun (#371)
* Implement Steam callback mechanism
* Implement Steam Networking
* Implement more of Steam remote storage
* Implement dirent API
* Check for shared config size between program and library
* Closing the game window takes effect even when paused (#65)
* Can remove multiple ram watches
* Implement greenzone using existing savestates (#134)
* Add an option to allow games to warp the mouse pointer (#378)
* Add nondraw frames in input editor
* Add Different By in Ram Search

### Changed

* Add timeout to timer when main thread polls and timeout
* Update input editor before game is launched (#340)
* Handle game closing a bit more cleanly
* Don't save movie savestates on disk until game exit

### Fixed

* Filter SDL1 active events (#351)
* Handle interrupts in socket messages (#342)
* Fix calls to XFreeEventData() when not GenericEvent (#361)
* Support partial ALSA audio buffer writing (#361)
* Stop screen capture on GL context destroy (#370)
* Don't set SDL_DYNAMIC_API for wine games
* Open natively a special file by jemalloc to avoid deadlock
* Check native events when XCheck*Event() returns nothing
* Free ScreenCapture when glx context is destroyed
* Prevent recursive calls to dlsym (#369)
* Fix getting monitor resolution for fake fullscreen
* Save clock_id per conditional variable
* sem_timedwait converts timeout relative to real time
* Forked processes are set to native
* Support spaces in commandline argument (#333)
* Handle when no font was found (#376)
* Fix init audio source volume and pitch when created
* When unavailable swresample, disable mixing instead of crashing
* Input editor: Support copy/delete any selection of rows

## [1.4.0] - 2020-06-19
### Added

* Add async SDL events handling (#166)
* Implement relative mouse inputs
* Add a setting to warp the pointer to the center of the screen after each frame
* Implement SteamHTTP and SteamGameCoordinator
* Users can use Proton instead of wine for launching Windows games
* Catch memory shortage in RAM Search
* Implement more behaviors of pointer grabbing
* Option to disable audio completely (some games don't accept that and quit)
* Hook LdrGetProcedureAddress() by patching ntdll.dll.so
* Add a full wait setting
* Add thread synchronization methods
* Introduce game-specific settings
* Input Editor colors are adapted from the chosen Qt5 theme (#308)
* Toggle every other input in editor with Ctrl+Click
* Fill SDL event windowId field
* Add a minimum value for input editor column width, because the default value
  is too high on some systems (#316)
* Add a Dockerfile and instructions to build the container
* Add sync setting for Hollow Knight
* Add epoll_wait hook (#321)
* Add snd_pcm_pause hook (#321)
* Add a converter from .hltas inputs
* Offer all common keys in the input mapping, even the ones not mapped in the
  user's keyboard layout
* We can add raw keyboard inputs to input editor (#326)
* Implement ALSA poll mechanism (#321)
* Grow the stack to its maximum at startup, to avoid unintialized stack growth (#337)
* Add variable framerate setting (#22)
* Encode at fixed framerate when variable framerate (#22)
* Check movie length at the end of playback

### Changed

* Monitor refresh rate now matches the framerate setting in libTAS
* Simplify the OpenGL performance setting
* Add horizontal scrollbar in the input editor (#316)
* Change the format of the input file, to make it more robust and adaptative (#332)
* Input Editor window can get behind main window (#334, #49)
* Home/End keys in the input editor move to top/bottom row (#335)
* Use periodic UI update for performance

### Fixed

* Don't use libavutil functions when configuring swresample context (#106)
* Fix a crash when seeking an audio source without attached buffers
* Memset unmapped memory when loading a savestate (#291)
* Don't link swr_free on AudioSource destructor (#294)
* Rearrange movie/config settings and their update on UI (#296)
* Fix restart toggle on input editor (#292)
* SDL Text Input is activated by default
* Fix input/hotkey mapping from config file (#302)
* Check mask size in XISelectEvents
* XI_RawMotion now uses raw inputs
* Track handles of savefiles
* Fill asynchronously fake /dev/urandom for games that read a large number of bytes (#310)
* Check for multiple opened pcm, and only keep the last opened
* Support multiple ALSA connections
* SDL relative mouse movement should ignore window clipping
* Add relative paths to savefiles
* Protect concurrent access to SaveFileList
* Support SDL_GameController* calls with null handle
* Set current cell when removing a row in input editor so that array keys work (#329)
* Fix locale names (#267)
* Fix when savefile was removed and re-opened (#267)
* Clear the event queue between game executions (#325)

## [1.3.5] - 2019-11-26
### Added

* Both 32-bit and 64-bit libtas.so libraries can be installed, and the program
  will select the correct one depending on the game arch
* Hook Xinerama for games gathering the monitor resolution
* Detect Windows executable and transparently call wine on it
* Add a loadbranch hotkey to load the entire savestate movie in playback mode
* Prevent the game screen from appearing unresponsive when the game is paused
* Don't scroll input editor after manual scrolling, until current frame is not visible
* Prevent monitor resolution change
* Add border/title on fullscreen window
* Check that GUI and library git commit match
* Controller connect/disconnect inputs
* Save Steam Remote Storage files to a game-specific directory
* Implement non-callback SDL Audio
* Implement SDL_GameControllerRumble and SDL_JoystickRumble
* Implement custom /dev/urandom and /dev/random Unity's UnityEngine.Random
* Implement custom /proc/uptime used by Unity's System.Random
* Prevent game window from staying on top
* XCB windows hooks
* XCB events hooks and keyboard/mouse events
* XCB pointer hooks
* Add a "No Wait" setting
* Add a xevent synchronization at frame end
* Support for multiple Steam class interfaces
* Implement OpenAL ALC_ALL_ATTRIBUTES parameter

### Changed

* Don't require /proc/self/pagemap to exist for savestating
* Switch to autotools
* More optimized Ram Search
* Synchronize xevents when a pop() didn't return an event, instead of when
  the event queue is empty (for cases when poped with event mask)
* Old LD_PRELOAD content is preserved

### Fixed

* Don't assume heap segments have the same protection
* Handle when state saving failed
* Fix insert frame not working after delete frame
* Better ALSA implementation
* Don't require specific swresample or avutil version
* Recursively create parent directories when creating a directory
* Sanitize SDL Audio specs
* Restore the game screen everytime, to avoid dirty buffers to be drawn

## [1.3.4] - 2019-04-08
### Added

* Add an extra row in the input editor to add frames and copy at the end
* Use appveyor for automated building
* Add support for SDL_UpdateWindowSurface() screen update
* Hook udev to populate joystick information
* Block access to pulseaudio, so that games fallback on alsa
* Drag analog inputs in the input editor
* Implement XI2 inputs
* Add some tooltips
* Handle wait timeouts
* Add an option to enforce determinism when events are pulled asynchronously
* Show recording/playback toggle in the OSD messages
* Store custom input names from the input editor in movies
* A thread creating a window is considered as the main thread
* Add shortcuts to some input editor options

### Changed

* Implement evdev/jsdev with pipes
* Remove time tracking all threads from movies/config
* Only offer to load a previous savestate movie if it's possible
* Remove the main thread condition in nondeterministic timer

### Fixed

* Fix SDL_BlitSurface hooking
* Fix a race condition on file handle list
* Fix evdev/jsdev hat inputs
* Enforce a minimum column size for analog inputs in the input editor
* Resize columns when it is needed
* Prevent zombie game processes

## [1.3.3] - 2019-02-08
### Added

* Implement more Xlib keyboard mapping functions
* When loading a savestate of previous game iteration, the movie is loaded
* Improve the support of virtual screen resolution for non-SDL games
* Prevent Xlib games to switch to fullscreen
* Implement an auto-restart feature
* Manually add audio latency for better playback
* Add a restart input
* Add an option to make a savestate each time the thread set has changed
* Lock inputs in the input editor

### Changed

* Take advantage of SDL2 dynamic linking mechanism for better SDL2 hooking
* Store files in $XDG_DATA_HOME and $XDG_CONFIG_HOME (usually ~/.local/share and ~/.config)

### Fixed

* Fix zeroing pages when incremental savestates feature is disabled
* Specifying a movie in commandline does not truncate the file anymore
* Fix a crash when renaming the frame column in input editor
* Fix behavior when SDL_JoystickOpen is called multiple times
* Print the correct char for common keys when typing text (non-SDL)
* Restore file offsets and close files when loading a savestate
* Fix a freeze in the input editor
* Fix a typo in SDL text input
* Make savefiles streams unbuffered to avoid data loss

## [1.3.2] - 2018-11-16
### Added

* Add locale setting
* Store md5 hash of game executable in movies
* Option to enable/disable dummy Steam client
* Implement OpenAL loop points
* Hook Xlib window resize
* Support for SDL1 rendering using surface blitting
* Mouse position recalibration to match game cursor position
* Add savestate slot to input editor
* Old autosaves are removed
* Autosave configuration window
* Desktop entry file
* ALSA mmap writing

### Changed

* Use system command for compressing/decompressing instead of tar/zlib libraries
* Implement more of the Steam API
* Register removed files as savefiles
* Rename program linTAS into libTAS

### Fixed

* Initialize audio sources that are reused
* Fix controller sliders
* Fix unsigned ints showed as signed in RAM Search
* Recreate texture/fbo when a new GL context is created
* Fix SDL1 keyboard layout
* Wait for threads to register
* Detect auto-repeat cases when detectable auto-repeat is not supported by the server
* Fix crash when loading a savestate on a non-draw frame
* End screen capture when SDL renderer is destroyed
* Register all connections to X server (for savestates) instead of just one
* Fix screen capture of SDL1 surface
* Autosave and exit save when movie is modified in the input editor
* Increment rerecord count if the movie was modified in the input editor

## [1.3.1] - 2018-08-30
### Added
- Xlib cursor and pointer warping functions
- Force FMOD to output to ALSA, and removed PulseAudio hooks
- Kill button to terminate a hanging game process
- Hook SDL text input
- Copy/cut/paste options in the input editor
- Start implementing Steam API to support some Steam games
- Support pthread keys for recycled threads, add add an option to disable thread recycling
- Movies can store annotations

### Changed
- Remove all ffmpeg API, and use a pipe to send video/audio using nut muxer

### Fixed
- Fix OpenAL deadlocks
- Change frame sleep logic to get fps closer to target fps
- Auto-repeat bug, which forced to disable xlib auto-repeat during the game execution
- Encode the first frame when starting encode before the game is launched
- Encode non-draw frames at game startup as blank frames
- Add encode segment number in encode filename
- Memory region permission is set when loading a savestate
- Fix some pointers overflow on 32-bit arch
- Audio buffers are cleared before calling the callback (SDL1 Audio)

## [1.3.0] - 2018-07-30
### Added
- Analog inputs in input editor, which are also editable
- Incremental savestates
- Store savestates in disk or RAM
- Simulates a system with english language
- Display ram watches on game screen
- Add pointers to ram watches
- Add a pointer scanning window to search for chains of indirection to a specific address
- Values can be poked into a game address
- Fast-forward skip modes
- Insert frames and truncate inputs in input editor

### Changed
- Some default fonts are chosen in priority for OSD
- Better savefile handling

### Fixed
- Set the repeat attribute in SDL2 key events, fixing keyboard inputs in SWD2
- Support thread exit with recycled threads
- Fix frame boundary trigger when game sleeps at startup, may affect sync

## [1.2.0] - 2018-05-28
### Added
- Input editor
- Recording mode when input editor is opened does not truncate the movie
- Recycle threads so that savestates always see the same number of threads
- OSD element can be positioned by the user
- Add messages on the OSD
- Add a status bar on the main GUI window

### Changed
- Offer fractional instead of integer framerate. This allows games like VVVVVV which uses 34ms frame interval to run at the exact speed without additional non-draw frames
- The whole movie is stored when savestating, not just the movie until the current frame. This way, users don't loose future inputs when using recording mode with input editor opened

### Fixed
- Don't add an extra frame when user stops the game
- Remove a memory leak caused by allocated keycode-keysym mapping
- Fix garbage inputs caused by uninitialized inputs when game does not have focus
- Always simulate the game window being on top-left corner so that games using global mouse coords do not desync
- Savestates work with audio not muted
- Change the way of hooking dlfoo functions because it broke on glibc 2.27 (now using `_dl_sym` to get the real dlsym)
- Fix the time increase at frame boundary when the game had some sleep calls, so that the time remains a multiple of the framerate increment
- Fix games using SDL mixer by replacing calls to `SDL_MixAudio` by `SDL_MixAudioFormat`, the former needed an audio device opened
- Always make logical and screen coords match on SDL2

## [1.1.1] - 2018-03-25
### Added
- Simulate a specific monitor resolution.
- Improve fastforward by skipping OpenGL draw functions.
- Initialize allocated memory with zeros, fixing desyncs in some games.
- Add author field in movie files.
- Add an option to pause at a specific frame.

### Changed
- Don't rely on the keyboard layout to determine keycodes from keysyms when feeding inputs to the game. Now using a standard qwerty keyboard layout.
- Changed the way to store the game screen when using OpenGL (using framebuffers and renderbuffers). Now the screen capture stays inside the GPU, except when doing an encode.

### Fixed
- Always display the last frame of a movie during a fast-forward, so that a TAS can be more easily resumed.
- Movie file browser does not ask for overwrite confirmation anymore.
- Add an extra movie frame corresponding to the game startup, so that frame count and system time now match. Old movies will desync, the user needs to add one blank frame at the beginning.
- Using both frame-advance and fast-forward now produces a faster frame-advance running speed.

## [1.1.0] - 2018-02-25
### Added
- Add full controller inputs, including analog inputs.

### Changed
- Switch from FLTK to Qt.
- Change the config file format and movie file format to use QSettings instead
of Fl_Preferences.

### Fixed
- Use stack_t type to fix a compile error on recent glibc.
- Fix a freeze when loading a savestate after a thread has been destroyed and
immediately created, in which case pthread library recycle the same id. Now
the state cannot be loaded in this case.
- Releasing the frame advance key with another key now correctly stops the
frame advance auto-repeat feature.

## [1.0.0] - 2018-02-09

Initial release.
