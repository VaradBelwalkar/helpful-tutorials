## The art of engineering WSL2

The reason why you can run powershell.exe from WSL 2 is because WSL 2 supports running Windows executables directly from the Linux command line. This is a feature of the WSL 2 architecture, which allows the Linux kernel to communicate with the Windows host through a special interface called 9P. 9P is a network protocol that enables file system and network operations to be performed across the virtual machine boundary.

When you run a Windows executable from WSL 2, such as powershell.exe, the following steps happen:

- WSL 2 checks if the executable has the .exe extension and is on the PATH environment variable. If not, it returns an error message.
- WSL 2 invokes the /init binary, which is the provisional binfmt_misc “interpreter” for the Windows executables. binfmt_misc is a Linux facility that allows launching binaries with arbitrary formats
- /init creates a new process on the Windows host using the CreateProcess API, and passes the executable name and arguments to it
- The Windows executable runs on the Windows host, and its standard input, output, and error streams are redirected to the WSL 2 terminal

This way, you can run Windows tools directly from the WSL 2 command line using [tool-name].exe. For example, notepad.exe. Applications run this way have the following properties:

- Retain the working directory as the WSL 2 command prompt (for the most part – exceptions are explained below).
- Have the same permission rights as the WSL 2 process.
