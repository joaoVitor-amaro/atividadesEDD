# -*- coding: utf-8 -*-
import time
from maze import Maze
from collections import deque

maze_csv_path = "labirinto1.txt"  # Substitua pelo caminho correto
maze = Maze() 

maze.load_from_csv(maze_csv_path)

maze.run()
maze.init_player()

time.sleep(1)  # espera o pygame abrir

maze.solve_backtracking()
