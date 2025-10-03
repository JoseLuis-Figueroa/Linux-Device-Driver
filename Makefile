# Add ldd.o to the list of kernel modules to be built
obj-m += ldd.o                

# Default target to build the module
all:                  
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
    # Invoke kernel build system in the current directory to build modules
# Target to clean up build artifacts
clean:                       
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
    # Invoke kernel build system to remove generated files