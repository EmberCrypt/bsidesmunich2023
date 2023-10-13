CC=v850-elf-gcc
LD=v850-elf-ld
OBJCOPY=v850-elf-objcopy

CFLAGS=-mrh850-abi
LDFLAGS=-L/usr/lib/libc -T rh850.lds

OUTFILE=test.out

all:
	$(CC) $(CFLAGS) -c vectors.S main.c
	$(LD) $(LDFLAGS) -o $(OUTFILE) vectors.o main.o
	$(OBJCOPY) -O binary $(OUTFILE) test.bin


clean:
	rm -f *.o *.out *.bin
