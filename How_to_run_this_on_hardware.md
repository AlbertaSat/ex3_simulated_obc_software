# Acquiring Cross Compilers
The container has already installed and setup the ARM Linux cross compiler packages, However, the F´ CMake system still needs the appropriate integration files to build. These files are called "CMake Toolchain". There is an F´ package that provides cross-compiler integration for standard ARM Linux cross-compilers (i.e. those provided as binary downloads from ARM).

To install the F´ ARM package, add it as a submodule in the main project directory via git:
```
git submodule add https://github.com/fprime-community/fprime-arm-linux.git
git submodule update --init --recursive
```

Now you must add this package to the Project Deployments ```settings.ini``` file by adding the following line:
```
[fprime]
...
library_locations: ../fprime-arm-linux
```

# Cross Compiling for ARM
Now cross-compiling is as easy as building the deployment for a specific platform. For users running on 64-bit arm the platform is called aarch64-linux, and for users on 32-bit linux use arm-hf-linux. This package expects the environment variable ARM_TOOLS_PATH to point to the installation directory of the ARM cross-compilers. This container has already set that environment variable to point to the /opt/toolchains/bin dir where the cross compilers are located.

Build the deployment for a 32-bit ARM Linux platform by entering the following code in your deployments directory:
```
# For ARM 32-bit hardware
fprime-util generate arm-hf-linux
fprime-util build arm-hf-linux
```

# Running on Hardware
Now it is time to run on hardware. The assumption is that the ARM Linux machine is available on the network, is running SSH, and the username, password, device address, and host address are known. 

First, in a terminal upload the software to hardware platform. This is done with:
```
# In the project deployment: <project>/<deployment>

# For ARM 32-bit hardware
scp -r build-artifacts/arm-hf-linux <username>@<device-address>:LedBlinker
```

Next run the F´ GDS without launching the native compilation (-n) and with the dictionary from the build above (--dictionary ./build-artifacts/<platform name>/LedBlinkerAppDictionary.xml).
```
# In <project>/<deployment>

# For ARM 32-bit hardware
fprime-gds -n --dictionary build-artifacts/aarch64-linux/dict/LedBlinkerAppDictionary.xml
```

In another terminal SSH into the device and run the uploaded software. Ensure the firewall port 50000 is open on host computer running gds:
```
ssh <username>@<device-address>
sudo <deployment>/bin/<deployment> -a <ip-of-computer-running-gds> -p 50000
```

## Congratulations you've now run on ARM hardware!