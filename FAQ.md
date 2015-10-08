# Introduction #

Here are some (somewhat) frequently asked question about Ksunil. Hopefully they will answer some of your frequent questions.


# F.A.Q. #

## General ##
#### What _is_ Ksunil, anyways? ####
Ksunil is an open source, lightweight Kernel. It is designed with simplicity, efficiency and speed in mind. We try to keep it as minimalistic as possible, while at the same time giving the user the power that he/she needs. Everything can (and should) be easily configured to the user's liking. _Everything_.

#### So this is free, right? ####
Yup! Everything (including the source code, of course) is offered completely free (both as in free beer and freedom of speech), because we believe completely in the Open Source and Free Software philosophies.

#### What license does Ksunil use? ####
Ksunil is under the GPLv3 license. You can read up on it [here](http://www.gnu.org/licenses/gpl-3.0.html).

#### But there are _tons_ of kernels out there. Why work on Ksunil? ####
We first started Ksunil as a way to test our skills in OS and kernel development. We wanted to write something simple that even the most novice developer could understand and learn from. It is by no means a replacement for existing kernels and OS's (Linux, for example), but it is a great learning tool!

#### What's this name "Ksunil" all about? ####
"Ksunil" is a double-reverse name: we reversed the phonetics of Linux (which would yield Skunil), then figured we'd reverse the first letter again, which gave us Ksunil. Clever, huh? ;-)

## Technical ##

#### In what language is Ksunil developed? ####
Ksunil is currently developed in C and x86 assembly, but mostly C.

#### How do I build Ksunil? ####
If you download the source, you will see a shell script called 'make.sh'. Simply run the command "sh make.sh" and everything will be built and linked for you, and the floppy image created. Here is what the make.sh file does:
```
nasm -f elf src/boot/bootsect.asm -o obj/bootsect.o

# Compile all the files
gcc -o obj/main.o -c src/kernel/main.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -o obj/port.o -c src/kernel/port.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -o obj/cursor.o -c src/kernel/cursor.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -o obj/memory.o -c src/kernel/memory.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -o obj/string.o -c src/kernel/string.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -o obj/screen.o -c src/kernel/screen.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector

# Link all object files into kernel.bin
ld -T linker.ld -o bin/kernel.bin obj/bootsect.o obj/main.o obj/port.o obj/cursor.o obj/memory.o obj/string.o obj/screen.o

# Create a floppy image
rm floppy.img
cat stage1 stage2 pad bin/kernel.bin > floppy.img
```

#### How do I run Ksunil? ####
We suggest using [QEMU](http://bellard.org/qemu/) for running the floppy image, though [Bochs](http://bochs.sourceforge.net/) should work, too. To run in QEMU, simply type:
```
qemu -fda floppy.img
```
QEMU might complain about KQemu not being present, or not having enough memory. In that case, run it with -no-kqemu. Simple, no? :D