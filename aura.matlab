function varargout = aura(varargin)
%AURA  Aura AI Platform Launcher
%
% Aura AI • XLSL • AI • Automation • Simulation
%
% Commands
%
% aura
% aura start
% aura help
% aura version
% aura status
% aura plugins
% aura update
% aura doctor
% aura simulate
% aura visualize
% aura deploy
% aura ethics
% aura collab
% aura config
% aura ai
% aura api
% aura stop

clc;
more off;

global AURA;

AURA.Version = "2.0.0";
AURA.Name    = "Aura";
AURA.Author  = "Seriki Yakub";
AURA.Root    = fileparts(mfilename('fullpath'));
AURA.Data    = fullfile(AURA.Root,"data","Aura.xlsl");
AURA.Config  = fullfile(AURA.Root,"config","config.json");
AURA.Logs    = fullfile(AURA.Root,"logs");

if nargin==0
    cmd="start";
else
    cmd=lower(string(varargin{1}));
end

try

switch cmd

case "start"

    aura_banner();

    aura_setpath(AURA.Root);

    aura_init();

    aura_load(AURA.Data,true);

case "nogui"

    aura_banner();

    aura_setpath(AURA.Root);

    aura_init();

    aura_load(AURA.Data,false);

case "doctor"

    aura_doctor();

case "plugins"

    aura_plugins();

case "config"

    aura_config();

case "version"

    fprintf("Aura %s\n",AURA.Version);

case "help"

    aura_help();

case "simulate"

    aura_run_simulations(AURA.Data);

case "visualize"

    aura_run_visuals(AURA.Data);

case "deploy"

    aura_deploy(AURA.Data);

case "ethics"

    aura_open_sheet(AURA.Data,"Ethics_Notes");

case "collab"

    aura_open_sheet(AURA.Data,"Collaboration_Log");

case "status"

    if evalin("base","exist('AURA_RUNNING','var')")
        disp("Aura is running");
    else
        disp("Aura is stopped");
    end

case {"stop","quit","exit"}

    aura_shutdown();

otherwise

    fprintf("Unknown command: %s\n",cmd);
    aura_help();

end

catch ME

    fprintf(2,"\nAURA ERROR\n");
    fprintf(2,"%s\n",ME.message);

    for k=1:length(ME.stack)
        fprintf(2,"%s:%d\n",ME.stack(k).file,ME.stack(k).line);
    end

end

if nargout
    varargout{1}=1;
end

end
