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
