![install_server](https://files.lmstudio.ai/deeplink/mcp-install-light.svg)
 
![add_me](https://files.lmstudio.ai/deeplink/mcp-install-dark.svg)

# 🧠 ProjectPilotAI

**ProjectPilotAI** is an AI-powered developer assistant that understands, analyzes, documents, and improves your codebase. It leverages cutting-edge large language models (LLMs), real-time file monitoring, GitHub integrations, and voice input to act as your second brain for software development.

## 🚀 Features

### 🔍 AI Codebase Analysis
- Summarize entire repositories with GPT-5 families
- Understand unfamiliar codebases in seconds

### ✨ Intelligent Refactoring (Pluggable)
- Catch smells, anti-patterns, and suggest best practices
- Hooks for custom GPT prompts and code transformation

### 🛠 Real-Time Dev Watchdog
- Monitor file changes
- Instantly suggest improvements or generate docs on file save

### 🤖 PR Review Bot (GitHub Actions)
- Automatically reviews pull requests
- Flags risky changes and suggests fixes using AI

### 📄 Auto-Documentation Generator
- Create or update `README.md`, module docstrings, and architecture maps

### 🧪 Security Scanner
- Detect `eval()`, insecure file access, missing `with` blocks, and more
- Pluggable AST-based Python linter

### 🔈 Voice Command & TTS
- Use Whisper to transcribe voice to code
- Hear summaries, file info, or project status aloud via TTS

### 💡 Natural Language Project Generator
- “Create a Flask API with Docker and tests” → Done.
- Fully code-generative workflow with AI chain of thought

### 🧰 VS Code Extension (WIP)
- Interact directly with the assistant from VS Code
- Generate functions, review diffs, or refactor selected code

### 🎨 Figma to Code Converter
- Converts Figma JSON into component code
- Useful for front-end engineers and designers
### 🌐 Streamlit Deploy UI
- Run the entire system from a sleek web GUI
- Upload a project, analyze, refactor, or summarize with one click

## 🧱 Architecture

```bash
project_pilot_ai/
├── ai_core/
├── cli/
├── gui/
├── integrations/
├── pilot_sdk/
├── voice/
├── .github/
└── vscode-plugin/
frontend/
  src/
    pages/
      dashboard.jsx
      studio.jsx
      lmlm.jsx
      preview.jsx
      api_keys.jsx
      admin.jsx
    components/
      Sidebar.jsx
      Navbar.jsx
      CodeEditor.jsx
      Terminal.jsx
      LivePreview.jsx
      DatasetView.jsx
      LMLMGraph.jsx
    utils/
      api.js
      auth.js
```

## 📜 License
MIT License © 2025 Web4application

![demo_link](https://github.com/user-attachments/assets/29b83d6b-2f1b-4da4-b5a2-2d5eec6c215e)


1. Workspace and build system
    * Root Cargo.toml
    * rust-toolchain.toml
    * .cargo/config.toml
    * GitHub Actions
    * Docker
    * Configuration system
2. propilot-core
    * Configuration
    * Logging
    * Error handling
    * Traits
    * Shared models
3. propilot-scanner
    * Recursive scanner
    * .gitignore support
    * Incremental indexing
    * File watcher
    * Parallel scanning
4. propilot-parser
    * Rust parser
    * TypeScript parser
    * JavaScript parser
    * Python parser
    * Go parser
    * Swift parser
    * Tree-sitter integration
5. propilot-graph
    * Import graph
    * Call graph
    * Module graph
    * Dependency graph
    * Graph algorithms
6. propilot-index
    * Symbol index
    * Search engine
    * Incremental updates
    * SQLite storage
7. propilot-analyzer
    * Dead code
    * Complexity
    * Architecture
    * Security
    * Performance
    * Dependency health
8. propilot-planner
    * Task prioritization
    * Feature decomposition
    * Risk analysis
    * Sprint planning
9. propilot-ai
    * Multi-provider support
    * Local models
    * RAG
    * Project Brain
    * Tool calling
10. propilot-server

* REST API
* gRPC
* WebSocket
* Authentication
* OpenAPI

11. propilot-cli

* scan
* analyze
* graph
* index
* plan
* ask
* doctor
* serve

12. Frontends

* Web dashboard
* VS Code extension
* Desktop app
* TUI

13. Plugins

* Rust
* Node.js
* Python
* Go
* Swift
* Docker
* Kubernetes
* Blockchain

14. Testing

* Unit tests
* Integration tests
* Benchmarks
* End-to-end tests

15. Deployment

* Docker Compose
* Kubernetes manifests
* CI/CD
* Release automation





* A Rust workspace with modular crates.
* A plugin architecture for language support.
* A persistent project index (“Project Brain”).
* Multi-model AI support (local and cloud).
* A REST/gRPC API for integrations.
* A web dashboard and CLI built on the same backend.

