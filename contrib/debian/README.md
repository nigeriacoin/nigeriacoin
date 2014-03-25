
Debian
====================
This directory contains files used to package nigeriacoind/nigeriacoin-qt
for Debian-based Linux systems. If you compile nigeriacoind/nigeriacoin-qt yourself, there are some useful files here.

## nigeriacoin: URI support ##


nigeriacoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install nigeriacoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your nigeriacoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/nigeriacoin128.png` to `/usr/share/pixmaps`

nigeriacoin-qt.protocol (KDE)

