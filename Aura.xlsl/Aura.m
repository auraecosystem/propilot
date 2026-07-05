function varargout = aura(varargin)
%==========================================================================
% AURA - Aura AI Hub Launcher
%
% Author : Seriki Yakub (KUBU LEE)
% Project: Aura Ecosystem (.xlsl)
% Version: 2.0.0
%
% Usage
%   aura
%   aura start
%   aura nogui
%   aura simulate
%   aura visualize
%   aura deploy
%   aura ethics
%   aura collab
%   aura reset
%   aura stop
%   aura status
%   aura version
%   aura help
%
%==========================================================================

more off

%% ------------------------------------------------------------------------
% Configuration
%% ------------------------------------------------------------------------

AURA.Version = "2.0.0";
AURA.Name    = "Aura";
AURA.Author  = "Seriki Yakub";
AURA.Home    = fileparts(mfilename('fullpath'));

AURA.DataDir = fullfile(AURA.Home,'data');
AURA.LogDir  = fullfile(AURA.Home,'logs');

AURA.Database = fullfile(AURA.DataDir,'Aura.xlsl');

if ~exist(AURA.LogDir,'dir')
    mkdir(AURA.LogDir);
end

%% ------------------------------------------------------------------------
% Parse Command
%% ------------------------------------------------------------------------

if nargin == 0
    command = "start";
else
    command = lower(string(varargin{1}));
end

result = true;

try

    switch command

        case "start"

            aura_banner(AURA);

            aura_setpath(AURA.Home);

            aura_log("Starting Aura Hub");

            assignin('base','AURA_RUNNING',true);

            aura_load(AURA.Database,true);

        case "nogui"

            aura_banner(AURA);

            aura_setpath(AURA.Home);

            aura_log("Starting Aura Hub (No GUI)");

            assignin('base','AURA_RUNNING',true);

            aura_load(AURA.Database,false);

        case "simulate"

            aura_log("Running simulations");

            aura_run_simulations(AURA.Database);

        case "visualize"

            aura_log("Generating visualizations");

            aura_run_visuals(AURA.Database);

        case "deploy"

            aura_log("Loading deployment");

            aura_deploy(AURA.Database);

        case "ethics"

            aura_open_sheet(AURA.Database,"Ethics_Notes");

        case "collab"

            aura_open_sheet(AURA.Database,"Collaboration_Log");

        case "reset"

            aura_log("Resetting Aura");

            aura_reset(AURA.Database);

        case {"stop","quit","exit"}

            aura_log("Stopping Aura");

            evalin('base','clear AURA_RUNNING');

            close all force

            clc

        case "status"

            result = evalin('base',...
                'exist(''AURA_RUNNING'',''var'')');

            if result
                fprintf("Aura Status : RUNNING\n");
            else
                fprintf("Aura Status : STOPPED\n");
            end

        case "version"

            fprintf("\n");
            fprintf("Aura %s\n",AURA.Version);
            fprintf("Author : %s\n",AURA.Author);
            fprintf("\n");

        case "help"

            aura_help();

        otherwise

            fprintf(2,"Unknown command: %s\n",command);

            aura_help();

    end

catch ME

    fprintf(2,"\nAURA ERROR\n");
    fprintf(2,"%s\n\n",ME.message);

    for k=1:length(ME.stack)
        fprintf(2," -> %s (%d)\n",...
            ME.stack(k).file,...
            ME.stack(k).line);
    end

    result = false;

end

if nargout

    varargout{1}=result;

end

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% PATHS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function aura_setpath(root)

folders = { ...
    "toolbox"
    "scripts"
    "core"
    "plugins"
    "simulation"
    "visualization"
    "deployment"
    "utils"
    };

for i = 1:length(folders)

    p = fullfile(root,folders{i});

    if exist(p,'dir')
        addpath(genpath(p));
    end

end

disp("AURA> Environment initialized.");

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% BANNER
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function aura_banner(AURA)

fprintf("\n");
fprintf("=========================================\n");
fprintf("        A U R A   A I   H U B\n");
fprintf("=========================================\n");
fprintf("Version : %s\n",AURA.Version);
fprintf("Author  : %s\n",AURA.Author);
fprintf("Home    : %s\n",AURA.Home);
fprintf("=========================================\n\n");

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% HELP
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function aura_help()

disp("Available Commands")
disp("------------------------------")
disp("aura")
disp("aura start")
disp("aura nogui")
disp("aura simulate")
disp("aura visualize")
disp("aura deploy")
disp("aura ethics")
disp("aura collab")
disp("aura reset")
disp("aura stop")
disp("aura status")
disp("aura version")
disp("aura help")
disp("------------------------------")

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% LOGGER
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function aura_log(message)

fprintf("[AURA] %s | %s\n",...
    datestr(now,'yyyy-mm-dd HH:MM:SS'),...
    message);

end
