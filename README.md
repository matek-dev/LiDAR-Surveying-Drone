# LiDAR Scanning Drone for Infrastructure Analysis

This project aims to develop a **LiDAR-equipped UAV** for the **Department of Transportation (DOT)** to improve infrastructure inspections. By generating **high-resolution 3D models**, engineers can analyze bridges and other structures remotely in a **Virtual and Augmented Reality (VAR) environment**, reducing the need for costly and hazardous on-site inspections.

![IMG_4431](https://github.com/user-attachments/assets/0181724a-a60e-4e4c-9dd9-1ea0ac9833a6)


## Project Overview

Our custom-built UAV integrates **LiDAR technology** with a **Raspberry Pi 4** running **ROS 1 Noetic** to capture **3D point clouds** of infrastructure. The system automates data acquisition, processes **LiDAR scans in real-time**, and provides output files for digital analysis. 

The project involved:
- Designing and constructing a UAV optimized for **LiDAR payload**.
- Developing a **ROS-based LiDAR mapping system**.
- Automating the scanning process via a **custom Linux service**.
- Ensuring **seamless control via a DJI remote**.

## Hardware & Software Components

### Hardware
- **LiDAR Sensor**: [**Unitree Robotics LiDAR L1**](https://github.com/matek-dev/unilidar_sdk)
- **Processing Unit**: **Raspberry Pi 4** (Ubuntu 20.04)
- **Power Supply**: Talentcell Rechargeable 6000mAh
- **Custom Mounts**: 3D-printed **LiDAR, Raspberry Pi, and power supply mounts**
- **Controller**: DJI Remote + **FPV Headset**
- **Motors**: SunnySky X2814 Motors
- **Flight Controller (FC) and Electronic Speed Controller (ESC)**: SpeedyBee F405 Stack
- **Drone Power Supply**: HRB LiPo Battery 10,000 mAh
- **Video Transmission Unit**: DJI O3 Air Unit
- **Propellers**: 9x6 APC Propeller
  
### Software
- **Operating System**: Ubuntu 20.04
- **Flight Contoller Software**: Betaflight
- **LiDAR SDK**: [Unitree Robotics SDK](https://github.com/matek-dev/unilidar_sdk)
- **Point Cloud Mapping**: [LIO-Mapping for Unilidar](https://github.com/matek-dev/point_lio_unilidar)
- **Automation**: **Custom Linux service (`LiDAR Mapping.c`)** for remote-triggered scanning.

## My Contribution (LiDAR Sensing System)

I was responsible for the **LiDAR sensing and automation system**, including:

- **Hardware Integration**
  - Mounted **LiDAR L1, Raspberry Pi 4, and power supply** on the drone.
  - Designed and 3D-printed **custom mounts** for secure and lightweight installation.

- **Software Development**
  - Installed and configured **Ubuntu 20.04 + ROS 1 Noetic** on the Raspberry Pi.
  - Integrated **Unitree Robotics LiDAR SDK** into ROS for real-time scanning.
  - Set up **LIO-Mapping** to generate 3D point clouds from LiDAR data.
  - Developed a **Linux service to:
    - Detect input signals from the drone controller.
    - Automatically launch and terminate **LiDAR scanning & mapping** processes.
    - Ensure system stability on boot.

## Installation & Setup

### Prerequisites
- **Ubuntu 20.04** installed on a **Raspberry Pi 4**.
- **ROS 1 Noetic** installed and sourced.
- **Unitree Robotics LiDAR SDK** and **LIO-Mapping package** installed.
- **LiDAR_Mapping.c** installed and placed in /usr/local/bin/
- **LiDAR_Mapping.service** installed and placed in /etc/systemd/system/

### Steps
* **Reload Systemd and Enable the Service**
```
sudo systemctl daemon-reload
sudo systemctl enable LiDAR_Mapping.service
sudo systemctl start LiDAR_Mapping.service
```
or

* **Restart Raspberry Pi**


## Usage Instructions

1. Power on the drone with all sensing components attached.
2. Ensure the Raspberry Pi 4 boots properly. LED will flash three times signaling system is set.
3. Trigger the scan using the designated button on the drone controller.
4. The system will:
  * Start LiDAR scanning.
  * Begin point cloud mapping.
  * Stop scanning when the input signal is turned off.
5. Retrieve the 3D point cloud data for further analysis.

## Future Improvements

Implement fail-safe features (auto-land, obstacle detection).
Add RTK positioning for centimeter-level accuracy.
Enable real-time stitching of multiple 3D point clouds.

## Acknowledgments

* University of Connecticut (UConn) - College of Engineering
* Sponsor: Civil Engineering Graduate Department in conjunction with the Department of Transportation (DOT)
* Project Advisors: Jorge Paricio
* Team Members: Matthew Koniecko, Ed Wilkinson, Sean Tan, Patricio Salomon-Mir

## License

This project is licensed under the MIT License.

## Contact

For any questions or contributions, feel free to reach out.
📧 Email: matthew.koniecko@gmail.com
🔗 GitHub: github.com/matek-dev/
