from datetime import datetime, timezone

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from routers import ai, data, community

app = FastAPI(title="Project Pilot AI API", version="1.0.0")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

app.include_router(ai.router, prefix="/ai", tags=["AI"])
app.include_router(data.router, prefix="/data", tags=["Data"])
app.include_router(community.router, prefix="/community", tags=["Community"])


@app.get("/")
def root():
    return {
        "message": "🚀 Project Pilot API is live",
        "service": "PilotAI",
        "status": "active",
        "metadata": "/metadata",
        "health": "/health",
    }


@app.get("/health")
def health():
    return {
        "status": "ok",
        "service": "PilotAI",
        "environment": "cloud",
        "timestamp": datetime.now(timezone.utc).isoformat(),
    }


@app.get("/metadata")
def metadata():
    return {
        "meta_version": "1.0",
        "project": "PilotAI",
        "environment": "cloud",
        "name": "PilotAI Cloud Intelligence Node",
        "status": "active",
        "capabilities": [
            "multimodal-orchestration",
            "task-analysis",
            "repository-analysis",
            "github-automation",
            "memory",
            "tool-routing",
            "verification",
        ],
        "event": {
            "type": "cloud_endpoint",
            "source": "ngrok",
            "action": "route",
        },
        "connection": {
            "integrations": ["ngrok", "FastAPI", "GitHub"],
            "latency_ms": "runtime",
        },
        "expansion": {
            "ai_mode": "multimodal",
            "security_protocol": "TLS + traffic-policy",
            "future_hooks": True,
            "signed_by": "PilotAI",
        },
        "timestamp": datetime.now(timezone.utc).isoformat(),
    }
