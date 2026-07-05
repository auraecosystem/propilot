![MIT License](https://img.shields.io/github/license/Web4application/pro_pilot_ai#License-MIT-lightgrey.svg)
![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)
![Python](https://img.shields.io/badge/Language-Python-blue.svg)
![Status](https://img.shields.io/badge/Status-Active-success.svg)
![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)
![Web4](https://img.shields.io/badge/Web4-Ready-00bfff.svg)
[![GitHub Actions Demo](https://github.com/Web4application/pro_pilot_ai/actions/workflows/github-actions-demo.yml/badge.svg)](https://github.com/Web4application/pro_pilot_ai/actions/workflows/github-actions-demo.yml)

# 🧠 ProjectPilotAI

A powerful AI-driven assistant designed to guide your entire software development workflow — from project setup and code review to blockchain interaction and smart contract integration.

## 🚀 Overview

**ProjectPilotAI** is your AI-powered project co-pilot that:
- Automates code analysis and project initialization
- Integrates directly with your GitHub repositories
- Supports smart contract deployment and Web3 interactions
- Powers up Fadaka Blockchain features like wallet generation, transaction handling, token mint/burn/swap, and more

> Deployed GitHub Page: 🌐 [web4application.github.io/project_pilot_ai](https://web4application.github.io/project_pilot_ai)

---

## 🧩 Features

- 🧠 **AI Assistant Interface** – GPT-powered project interaction via CLI and Web
- 💾 **Local & GitHub Code Parsing** – Analyze and refactor entire repositories
- 🔐 **Wallet + Key Management** – HD wallet generation, transaction signing
- 🔄 **Fadaka Blockchain Integration** – Smart contract deployment, faucet, mint/swap
- 📡 **Live Transaction Tracking** – With confirmation checks and event logs
- 📦 **FastAPI Backend** – API for signing, broadcasting, and fetching TX data
- 🖥️ **Web UI Support** – Jekyll dashboard with real-time updates and blockchain tools

---

## 🏗️ Project Structure

```bash
pro_pilot_ai/
├── app/                   # Main Python app
│   ├── core/              # AI logic & command handlers
│   ├── blockchain/        # Fadaka integration (wallets, txs, etc.)
│   └── web/               # FastAPI server + API routes
├── templates/             # HTML templates for the UI
├── static/                # JS/CSS for Web Dashboard
├── README.md              # (You're here)
└── requirements.txt       # Python
dependencies

```

 ## ⚙️ Setup Instructions

### ✅ Prerequisites

* Python 3.9+
* Node.js (optional, for frontend)
* GitHub Personal Access Token (if using GitHub features)

### 🛠️ Installation

```bash

git clone https://github.com/Web4application/pro_pilot_ai.git
cd pro_pilot_ai
pip install -r requirements.txt
```

### 🚀 Run the AI Assistant Web API

```bash

uvicorn app.web.main:app --reload --port 3000
```

Visit: [http://127.0.0.1:3000](http://localhost:8000)

---

## 💡 Usage

You can use the assistant to:

* 🧠 Chat with your projects via CLI or browser
* 📁 Upload code and get suggestions or fixes
* 💬 Ask to deploy or interact with smart contracts
* ⚡ Sign and broadcast transactions to Fadaka
* 🧪 Test Web3 logic via faucet, mint/burn, and swap tools

---

## 🌍 Deployment Options

* [x] GitHub Pages (Jekyll-ready)
* [x] Render / Railway / fly.io (FastAPI backend)
* [ ] Electron / PyInstaller desktop packaging (coming soon)

---

## 🛡️ Security

* Wallets are generated locally with HD seed logic
* Transaction signing uses secure in-memory operations
* API protected via headers (optionally OAuth)

---

## 🤝 Contributing

We welcome contributions!

```bash

git clone https://github.com/Web4application/pro_pilot_ai.git
propilot.ai
# Create feature branch, make your changes, then:
git push origin feature-branch
```

Please open a pull request with a clear description of your changes.

---

## 📄 License

Licensed under the MIT License.
© 2025 [Web4Application](https://github.com/Web4application)

---

## ✨ Acknowledgements

* Fadaka Blockchain Core
* GPT-4 Project Pilot Intelligence
* FastAPI, Web3.py, and Hardhat
* Web4 — The Future of Decentralized Apps

---

## 🔗 Related Projects

* [Fadaka Blockchain](https://github.com/Web4application/fadaka-blockchain)
* [Swift Beta Wallet](https://web4application.github.io/project_pilot_ai)





![ProjectPilotAI Preview](./projectpilot_readme_preview.png)
