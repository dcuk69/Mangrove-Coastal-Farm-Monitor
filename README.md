# 🌿 Mangrove & Coastal Farm – IoT Monitoring & Automation System

A smart monitoring and automation system designed for coastal and mangrove farming regions.  
The project addresses tidal flooding, salinity intrusion, and environmental variability using an **ESP32 microcontroller**, environmental sensors, cloud integration, and automated actuators.

---

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Hardware Components](#hardware-components)
- [Software & Cloud Services](#software--cloud-services)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [1. ThingSpeak Setup](#1-thingspeak-setup)
  - [2. ESP32 Firmware](#2-esp32-firmware)
  - [3. Web Dashboard](#3-web-dashboard)
- [Usage](#usage)
- [Customization](#customization)
- [Future Enhancements](#future-enhancements)
- [Credits & Team](#credits--team)

---

## Overview

Coastal and mangrove farms face extreme conditions: tidal flooding, salinity spikes, and a lack of real‑time monitoring.  
This system continuously measures:

- **Temperature & Humidity**  
- **Soil Moisture**  
- **Water Level**  
- **Light Intensity**  

It then automates two critical actions:

- **Flood Gate Control** – Opens/closes based on water level thresholds.  
- **Pump / Aerator Control** – Activates when temperature or salinity exceeds safe limits.  

All data is sent to **ThingSpeak** and visualised in a **clean, real‑time web dashboard**.

---

## Features

- ✅ Real‑time environmental monitoring (5 parameters)  
- ✅ Automated flood gate (servo motor)  
- ✅ Automated pump/aerator (relay control)  
- ✅ Cloud data logging via ThingSpeak (Wi‑Fi or GSM)  
- ✅ Live web dashboard (HTML, CSS, vanilla JS)  
- ✅ Visual alerts for high water / high temperature  
- ✅ Modular design – easily extendable  

---

## System Architecture

[ Sensors ] → ESP32 → [ Actuators (Servo, Pump) ]
|
v
ThingSpeak Cloud
|
v
Web Dashboard (HTML/JS)


- **Sensors** measure environment.  
- **ESP32** processes data, applies decision logic, controls actuators, and uploads to cloud.  
- **ThingSpeak** stores data and provides JSON API.  
- **Web Dashboard** fetches the latest data every 5 seconds.

---

## Hardware Components

| Component               | Purpose                               |
|------------------------|---------------------------------------|
| EESP32 Dev Board        | Microcontroller + Wi‑Fi               |
| DHT22 (or DHT11)        | Temperature & Humidity                |
| Soil Moisture Sensor    | Soil water content                    |
| Water Level Sensor      | Tidal / flood detection               |
| Light Sensor (LDR/BH1750) | Light intensity                     |
| Servo Motor (e.g., SG90) | Flood gate opener/closer             |
| Relay Module + Pump     | Water circulation / aeration          |
| Optional: SIM800/SIM900 | GSM/GPRS connectivity (alternative)   |
| Jumpers & Breadboard    | Connectivity                          |

> **Note:** If using GSM, you’ll need an active SIM card with a data plan and the APN configured.

---

## Software & Cloud Services

- **ThingSpeak** – Free IoT platform (required)  
- **Arduino IDE** – ESP32 programming (C++)  
- **Web Browser** – Any modern browser (Chrome, Edge, etc.)  
- **Libraries** (Arduino): `WiFi.h`, `HTTPClient.h`, `DHT.h`, (optional `TinyGSM` for GSM)

---

## Project Structure

📁 Mangrove_Farm_IoT/
├── 📄 README.md
├── 📄 dashboard.html # Web dashboard (open in browser)
├── 📁 esp32_code/
│ ├── esp32_wifi_upload.ino # Firmware using Wi‑Fi
│ └── esp32_gsm_upload.ino # Firmware using GSM/GPRS
└── 📄 thingSpeak_channel_setup.md # (optional) channel settings


---

## Getting Started

### 1. ThingSpeak Setup

1. Create a free account at [ThingSpeak.com](https://thingspeak.com).  
2. Create a **New Channel** with the following **7 fields**:  

   | Field | Label             | Unit | Values      |
   |-------|-------------------|------|-------------|
   | 1     | Temperature       | °C   | Float       |
   | 2     | Humidity          | %    | Float       |
   | 3     | Soil Moisture     | %    | 0–100       |
   | 4     | Water Level       | %    | 0–100       |
   | 5     | Light Intensity   | lux  | Float/int   |
   | 6     | Gate Status       | 1/0  | Open/Closed |
   | 7     | Pump Status       | 1/0  | ON/OFF      |

3. Go to **API Keys** tab and note:
   - **Channel ID** (used in dashboard and firmware)
   - **Write API Key** (for ESP32 – keep private)
   - **Read API Key** (for dashboard – can be public)

---

### 2. ESP32 Firmware

**Option A – Wi‑Fi (recommended first)**  

- Open `esp32_wifi_upload.ino` in Arduino IDE.  
- Install required libraries (DHT, ESP32 board).  
- Replace placeholders:  
  ```cpp
  const char* ssid = "YOUR_WIFI_SSID";
  const char* password = "YOUR_WIFI_PASSWORD";
  const String WRITE_API_KEY = "YOUR_WRITE_API_KEY";


  
