# obc_software_nextgen_test
Fprime software project to be ran on an embedded linux OS

&nbsp;

## Usage
It is recommended that you use the devcontainer I have setup here: https://github.com/AlbertaSat/CUBICS_Fprime_Devcontainer. Using this docker container will ensure all contributing members have a very similar dev environment, despite their host machine configuration. 

**For now the project does not include a copy of the fprime library.** You will have to clone the https://github.com/nasa/fprime repo yourself. Be sure that you modify the settings.ini framework_path to point to it.

&nbsp;

### Use without a python venv 
For now this project is setup without a python virtual env, which is used throughout the provided NASA tutorials. Given a docker container has been setup this seems redudant but may change in the future. In order to use the fprime-tools (fprime-util fprime-gds etc..) you will need to install the extra necessary python libraries found in fprime/requirements.txt file using pip with the following command: 
```
pip -r {location_to_fprime_dir}/fprime/requirements.txt
```

The docker container also adds /home/$USER/.local/bin to your PATH. If you are not using it you must do this. This can be done with the following line: 
```
echo 'export PATH=$PATH:$HOME/.local/bin' >> /home/$USERNAME/.bashrc
```


&nbsp;

## Contributing

### Branch naming conventions: 
The following branch naming conventions must be followed. Any PR not in compliance will be denied. The naming convention going is as follows:

<name_of_author>/<branch_type>/<description_of_branch>

The following is a list of possible branch types:   
- feature
- testing
- bugfix
- hotfix
- documentation

### Branching etiquette
- Branches must implement/change only a single feature. Changes related to that feature across different layers of code is acceptable.
- You may create branches off branches, but they will be merged in the order they were created. You also need to be prepared to accept the risk of having to rebase to a new parent branch parent branch, should those changes be declined.
- If you discover a bug unrelated to the feature you are working on, switch back to master, make a branch to fix the feature, then make a PR to merge that Bugfix. Chances are you aren't the only one experiencing the bug. You may rebase your development branch off the Bugfix branch.
- Branches that do not describe what they are changing will not be accepted.


### Commenting etiquette
- Good code should explain itself
- As we learn and improve the code for this repo it would be best if non obvious classes and functions were included with a brief explanation of how they work from a high level. 
- Given we are a student organization its best if the code we write can be easily and quickly understood by those of varying skill levels and backgrounds. That being said if you think something should be commented, then comment it.

