type t = {
  id: string,
  name: string,
  version: string,
  sourceType: EsyLib.SourceType.t,
  buildType: EsyLib.BuildType.t,
  build: list(list(Config.Value.t)),
  install: option(list(list(Config.Value.t))),
  sourcePath: Config.Value.t,
  rootPath: Config.Value.t,
  buildPath: Config.Value.t,
  stagePath: Config.Value.t,
  installPath: Config.Value.t,
  env: EsyLib.Environment.Make(Config.Value).t,
  files: list(File.t),
  jbuilderHackEnabled: bool,
};

include EsyLib.S.COMPARABLE with type t := t;
include EsyLib.S.JSONABLE with type t := t;

let ofFile: EsyLib.Path.t => Run.t(t, _);
