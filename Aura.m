switch command

    case "start"
        aura_start(AURA);

    case "nogui"
        aura_nogui(AURA);

    case "simulate"
        aura_simulate(AURA);

    case "visualize"
        aura_visualize(AURA);

    case "deploy"
        aura_deploy(AURA);

    case "ethics"
        aura_ethics(AURA);

    case "collab"
        aura_collab(AURA);

    case "plugin"
        aura_plugin(varargin{2:end});

    case "model"
        aura_model(varargin{2:end});

    case "api"
        aura_api(varargin{2:end});

    otherwise
        aura_help();

end
