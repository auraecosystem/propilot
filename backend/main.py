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


def _now() -> str:
    return datetime.now(timezone.utc).isoformat()


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
        "timestamp": _now(),
    }


@app.get("/metadata")
def metadata():
    """Machine-readable PilotAI Cloud Endpoint contract."""
    timestamp = _now()
    return {
        "meta_version": "1.0",
        "project": "PilotAI",
        "environment": "cloud",
        "region": "auto",
        "build": "propilot-main",
        "uptime": "managed",
        "timestamp": timestamp,
        "id": "pilotai-cloud-endpoint",
        "name": "PilotAI Cloud Intelligence Node",
        "capabilities": [
            "multimodal-orchestration",
            "task-analysis",
            "repository-analysis",
            "github-automation",
            "memory",
            "tool-routing",
            "verification",
        ],
        "status": "active",
        "event": {
            "type": "cloud_endpoint",
            "source": "ngrok",
            "summary": "PilotAI cloud gateway",
            "action": "route",
            "memory": "ready",
        },
        "connection": {
            "ecpusage": "runtime",
            "memory_usage": "runtime",
            "latency_ms": "runtime",
            "integrations": ["ngrok", "FastAPI", "GitHub"],
            "endpoint": "/",
        },
        "expansion": {
            "ai_mode": "multimodal",
            "security_protocol": "TLS + traffic-policy",
            "future_hooks": True,
            "signed_by": "PilotAI",
            "checksum": "runtime",
        },
    }
