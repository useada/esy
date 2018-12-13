module Path = EsyLib.Path;

module Env = EsyLib.Environment.Make(Config.Value);

[@deriving (yojson, ord)]
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
  env: Env.t,
  files: list(File.t),
  jbuilderHackEnabled: bool,
};

let ofFile = (path: Path.t) => {
  module Let_syntax = EsyLib.Result.Syntax.Let_syntax;
  let%bind data = Run.read(path);
  let json = Yojson.Safe.from_string(data);
  switch (of_yojson(json)) {
  | Ok(plan) => Ok(plan)
  | Error(err) => Error(`Msg(err))
  };
};
