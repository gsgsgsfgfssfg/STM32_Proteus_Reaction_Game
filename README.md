# Reaction Time Game

A reaction time game implemented using **Embedded C on STM32F103C6**, featuring a Finite State Machine (FSM), a cooperative scheduler based on a Delta Queue, and an Independent Watchdog (IWDG).

The project focuses on practicing embedded software architecture, non-blocking execution, task scheduling, and basic system reliability mechanisms.

## Demo

[Watch the project demonstration on YouTube](https://www.youtube.com/watch?v=kclBhMvZg5o)

## Features

- **Reaction Time Game:** Test the player's reaction speed using a single push button.
- **LED Countdown:** Five LEDs illuminate sequentially before the reaction phase.
- **Random Waiting Period:** A random delay of 1–4 seconds prevents the player from predicting the start signal.
- **Early Press Detection:** Detects button presses before the READY signal.
- **Reaction Timeout:** Players have 1000 ms to respond after the READY signal.
- **Visual Feedback:** Separate LEDs indicate WIN, LOSE, EARLY PRESS, and button input detection.
- **Cooperative Scheduling:** A Delta Queue-based scheduler manages periodic tasks without blocking execution.
- **Independent Watchdog:** Uses the STM32 Independent Watchdog to provide basic protection against scheduler execution failures.

## Hardware Requirements

| Component | Description |
|---|---|
| Microcontroller | STM32F103C6 |
| Push Button | 1 |
| Game LEDs | 5 |
| Win LED | 1 |
| Lose LED | 1 |
| Early Press LED | 1 |
| Input Debug LED | 1 |

**Hardware configuration:**
- SYSCLK: 8 MHz
- Development environment: STM32CubeIDE
- Simulation environment: Proteus 8.10

### GPIO Pin Mapping

| Component | GPIO |
|---|---|
| Push Button | PB4 |
| Game LEDs (1–5) | PA3–PA7 |
| Win LED | PB2 |
| Lose LED | PB3 |
| Early Press LED | PB5 |
| Button Input Debug LED | PB7 |

## Game Flow

The game is controlled by a Finite State Machine.

1. **IDLE:** Wait for the player to press the button.
2. **COUNTDOWN:** Five game LEDs illuminate sequentially.
3. **WAIT:** All five LEDs remain ON for a random duration between 1 and 4 seconds.
4. **PLAY:** All five game LEDs turn OFF. The reaction timer starts.
5. **WIN:** The player presses the button within 1000 ms.
6. **LOSE:** The player fails to respond within 1000 ms.
7. **EARLY:** The player presses the button before the READY signal.

The result remains displayed until the player presses the button to start another round.

## Software Architecture

The project is organized into independent modules with clearly defined responsibilities.

| Module | Responsibility |
|---|---|
| Game FSM | Manages game states and transitions |
| Input Manager | Handles button input and debouncing |
| LED Manager | Controls game LEDs, result indicators, and input feedback |
| Random Generator | Generates random waiting durations |
| Scheduler | Manages periodic task execution |
| Watchdog Manager | Initializes and refreshes the Independent Watchdog |

### Non-blocking Execution

The game uses timestamp-based timing instead of blocking delays.

Countdown intervals, random waiting periods, reaction time measurement, and LED blinking are handled through elapsed-time checks.

This allows the scheduler to continue executing other tasks while the game is waiting for a particular event.

## Cooperative Scheduler

The scheduler uses a **Delta Queue** to manage task execution.

### Scheduler Configuration

| Parameter | Value |
|---|---|
| Scheduler Tick | 10 ms |
| Scheduling Algorithm | Delta Queue |
| SCH_Update() Complexity | O(1) |
| Execution Model | Cooperative Scheduling |

### Registered Tasks

| Task | Period | Responsibility |
|---|---:|---|
| Input Task | 10 ms | Reads and processes button input |
| Game FSM Task | 10 ms | Updates game state and transitions |
| LED Task | 10 ms | Updates button input debug LED |
| Watchdog Task | 100 ms | Refreshes the Independent Watchdog |

The scheduler uses a hardware timer interrupt to maintain its 10 ms system tick.

Task execution takes place in the main loop rather than inside the timer interrupt handler.

## Watchdog Management

The project uses the STM32 **Independent Watchdog (IWDG)**.

| Parameter | Configuration |
|---|---|
| Watchdog Type | IWDG |
| Approximate Timeout | 2 seconds |
| Refresh Interval | 100 ms |

A dedicated scheduler task periodically refreshes the watchdog.

The watchdog provides basic protection against failures that prevent the scheduler from executing the watchdog refresh task.

**Limitation:** The current implementation does not maintain individual task heartbeats. Therefore, it does not independently verify that every application task is making progress.

Watchdog reset behavior has not yet been verified in Proteus.

## Testing and Simulation

The project has been successfully simulated using Proteus 8.10.

The following gameplay scenarios have been tested:

- Normal countdown sequence.
- Random waiting period.
- Early button press detection.
- Successful reaction within the timeout.
- Reaction timeout and loss condition.
- LED feedback and restarting the game.

The IWDG reset mechanism has not been verified through Proteus simulation.

## Build and Run

1. Open the project using STM32CubeIDE.
2. Build the firmware.
3. Open the Proteus project file (`Reaction_Game.pdsprj`).
4. Load the generated firmware into the STM32F103C6 component.
5. Run the simulation.

## Technologies

- Embedded C
- STM32F103C6
- STM32 HAL
- STM32CubeIDE
- Proteus 8.10
- Finite State Machine (FSM)
- Cooperative Scheduling
- Delta Queue
- Independent Watchdog (IWDG)

---

**Project Focus:** Embedded C programming, modular software design, non-blocking execution, cooperative task scheduling, and watchdog fundamentals.