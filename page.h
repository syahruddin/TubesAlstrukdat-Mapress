#ifndef PAGE_H
#define PAGE_H
#include <stdio.h>
#include <stdlib.h>
#include "play.h"

void CoverPage();
// Menampilkan "Diner Dash" wkwkwkw

void FrontPage();
// Tampilan awal pada game

void StartGame(char name[]);
// Memulai game (membaca map)

void LoadGame();
// Memulai game yang telah tersave (membaca map)

void BacaMap();
// Membaca Map

void TulisMap();
// Menampilkan Map

void Exit();
// Keluar dari game


#endif
