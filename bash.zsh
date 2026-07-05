# set checkForUpdatesAutomatically to false
jlab config set checkForUpdatesAutomatically false
# set theme to "dark"
jlab config set theme "dark"
# set the global default Python path for JupyterLab server
jlab config set pythonPath /Users/username/custom_env/bin/python
# set the default Python path for JupyterLab server for project at current working directory
jlab config set pythonPath /Users/username/custom_env/bin/python --project
# set the default Python path for JupyterLab server for particular project
jlab config set pythonPath /Users/username/custom_env/bin/python --project-path=/opt/test-project
# set conda channels to ["conda-forge", "bioconda"] on Windows
jlab config set condaChannels [\"conda-forge\",\"bioconda\"]
# set conda channels to ["conda-forge", "bioconda"] on macOS and Linux
config set condaChannels '["conda-forge","bioconda"]'
