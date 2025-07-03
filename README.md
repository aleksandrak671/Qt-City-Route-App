# Qt City Route App

A small academic project developed at Warsaw University of Technology. This desktop Qt application visualizes Polish cities and computes the shortest route between them using Dijkstra’s algorithm.

---

## Features

- Loads city connections from a text file  
- Interactive GUI built with Qt  
- Draws cities and roads on a map (with optional background map)  
- Uses Dijkstra's algorithm to find the shortest path  
- Highlights the shortest path in red  
- Combo boxes to choose start and end cities  
- Displays route as text with total distance

---

## How It Works

- The app reads connections between cities from a text file (`miasta.txt`) in this format:

CityA CityB Distance

CityB CityC Distance

- It builds an undirected weighted graph.
- Users select the start and end cities from dropdown menus.
- The app runs Dijkstra’s algorithm to find the shortest path.
- It draws:
- All roads (edges) in grey
- Cities as blue dots with labels
- The shortest path in red

---

## Build Instructions

- Requires Qt (tested with Qt 6)  
- Uses CMake
