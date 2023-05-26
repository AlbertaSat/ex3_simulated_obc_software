# Configuring this dev environment for vs code

You must have vscode and docker installed on your computer.
In vscode, open the extensions menu and search for "Dev Containers." Install the Dev Containers extension by Microsoft

This docker image is configured to automatically write your command history to a folder called 'persistent' on your host machine. It does this using something called a bind-mount, which attaches a file or folder on your local machine to the docker container. You must ensure your host machine has this folder in the same parent folder alongside the .devcontainer folder. If this does not exist the docker build will fail, mentioning the source path for the requested mount does not exist. 

Open the command pallete by hitting "F1" (and maybe the fxn key) on your keyboard. 
Search for "Dev Containers" and select "Open folder in container"
Navigate to this folder and open it. 

Vscode will now create the docker container found in .devcontainer/Dockerfile. This is a debian based container, real development should use whatever ships with the OBC we plan to run this on such as yocto (used by xiphos)
On the bottom right you can click the "opening container" notification to see the progress. 

If you the container does not build due to an error you can try to remove all hanging container instances that may be preventing it from building with the following command. Be sure to  close any vscode windows that are or have been attached to a docker container. 
```
docker system prune -a
```

Once the docker container is built, open a new bash terminal by clicking + on the right in vscode.