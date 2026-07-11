# my_factory

A C++20 game engine foundation built with SFML, designed around a modular architecture. The project sets up the core infrastructure for a factory-themed game, including a rendering layer, a network server stub, a resource preloader, a character system, and a structured logging system.

---

## Dependencies

| Library | Purpose |
|---|---|
| **SFML** (graphics, window, system, audio, network) | Window management & rendering |
| **libconfig++** | Configuration file parsing |
| **g++ (C++20)** | Compiler |

---

## Build

```bash
# Build the project
make

# Clean object files
make clean

# Full clean (objects + binary)
make fclean

# Rebuild from scratch
make re
```

The resulting binary is `my_factory`.

---

## Usage

```
./my_factory [OPTIONS]

OPTIONS
    -h, --help          Display this help message
    -p, --port <port>   Specify the server port (default: 8080)
    -H, --hostname <h>  Specify the hostname (default: 127.0.0.1)
```

---

## Architecture

The project is organised around a clear module separation under `my_factory_project/`:

```
my_factory_project/
├── include/
│   ├── Core/           # Core, Parser, Preloader, Server
│   ├── Game/
│   │   ├── Character/  # ICharacter, ACharacter, CCharacter, Player, Other
│   │   └── Component/  # (reserved for future components)
│   ├── SFML/           # SFMLManager, SimplifiedSFML
│   ├── Log/            # LogManager (singleton)
│   └── Utils/          # Shared types, macros, version info
└── source/
    ├── main.cpp
    ├── conditions.cpp
    ├── Core/           # Core, Parser, Preloader, Server implementations
    ├── Game/Character/ # Character implementations
    ├── SFML/           # SFMLManager, SimplifiedSFML implementations
    └── Log/            # LogManager implementation
```

---

## Modules

### Core (`Factory::Core`)

The central orchestrator. `Core::run()` sequentially initialises all subsystems and enters the game loop.

- **`Core`** — Owns the `ServerManager`, `PreloaderManager`, and `SFMLManager`. Drives `init → loop`.
- **`ServerManager`** (`Factory::Server`) — Holds host/port configuration. Handles connection initialisation and event polling.
- **`PreloaderManager`** (`Factory::Preloader`) — Stub for loading assets before the game loop starts.
- **`Parser`** (`Factory::Parser`) — Stub for configuration/data file parsing.

### Rendering (`Factory::SFML`)

- **`SFMLManager`** — Owns the `sf::RenderWindow`, a delta `sf::Clock`, and a base font. Exposes `init()`, `getInput()`, and `render()`.
- **`SimplifiedSFML`** — A thin SFML wrapper layer (in progress) to abstract common draw calls.

### Character System (`MyFactory::Character`)

A classic inheritance hierarchy:

```
ICharacter          (pure interface)
    └── ACharacter  (abstract base: id, name, 3D position via Axis_t)
            ├── PlayerCharacter   (the player-controlled entity)
            └── OtherCharacter    (NPCs / other entities)
```

- **`CCharacter`** — A container/manager that holds a collection of `ICharacter` instances. Provides add, remove, lookup by index, ID availability checks, and display helpers.

### Logging (`Log`)

- **`LogManager`** — Singleton logger. Writes timestamped entries to a log file. Supports plain messages, messages with exceptions, and messages tagged with a source name (`from`).
- Log files are stored under `logs/`. The `logs/deleteLogs.sh` script wipes them.

### Utils

Shared across all modules via `Utils.hpp`:

| Item | Description |
|---|---|
| `Axis_t` | 3-component float coordinate struct (x, y, z) |
| `OUTPUT` enum | `NOERROR = 0`, `ERROR = 84` return codes |
| `PROJECT_VERSION` | Semver macro (`0.0.0.0`) |
| `MSG` / `ERR` | stdout / stderr convenience macros |
| `LOOP`, `DEFAULT`, `UNKNOWN` | Common sentinel constants |

---

## Project Status

| Module | Status |
|---|---|
| Build system (Makefile) | ✅ Done |
| CLI argument parsing | ✅ Done |
| Core init/run/loop skeleton | ✅ Done |
| LogManager (singleton) | ✅ Done |
| ServerManager (host/port init) | ✅ Skeleton |
| PreloaderManager | ✅ Skeleton |
| SFMLManager (window + font) | ✅ Skeleton |
| SimplifiedSFML wrapper | 🔧 In progress |
| Game loop | 🔧 Commented out / in progress |
| Character system (hierarchy) | ✅ Done |
| Component system | 🔧 Reserved / empty |
| Parser | 🔧 Skeleton |
| Map procedural generation | 📋 Planned |

---

## License

See [LICENSE](LICENSE).