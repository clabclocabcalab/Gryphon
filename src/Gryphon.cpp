#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <unistd.h>
#include "CPU.h"

using namespace std;

void fillFromFile(uint32_t array[], char filename[]);

int main(int argc, char** argv) {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    refresh();

    CPU cpu;
    uint32_t address = 0;
    uint32_t data = 0;

    uint8_t interrupt = 0;
    uint8_t reset = 1;

    uint32_t ROM[0x1000];
    fillFromFile(ROM, argv[1]);
    uint32_t RAM[0x1000];

    int key = 0;
    do {
        if (cpu.next(&address, &data, interrupt, 0, reset)) {
            if (address < 0x1000) continue;
            else if (address == 0x1000) { printw("%c", (char)data); refresh(); }
            else if (address == 0x1001) interrupt = 0;
            else if (address < 0x2000) RAM[address - 0x1000] = data;
        }
        else {
            if (address < 0x1000) data = ROM[address];
            else if (address == 0x1001) data = key;
            else if (address < 0x2000) data = RAM[address - 0x1000];
        }
        if (!interrupt) {
            int c = getch();
            if (c != ERR) {
                key = c;
                interrupt = 1;
            }
        }
        reset = 0;
    } while (key != 27);

    endwin();
    return 0;
}

void fillFromFile(uint32_t array[], char filename[]) {
	ifstream file(filename, ios::binary | ios::ate);
	if (!file.is_open()) {
		cout << "Error: file not found" << endl;
		return;
	}
	int size = file.tellg();
	file.seekg(0);
	char buffer[size];
	file.read(buffer, size);
	size /= 4;
	for (int i = 0; i < size; i++) {
        int a = 0;
        for (int j = 0; j < 4; j++) {
            a |= (uint8_t)buffer[i * 4 + j] << (j * 8);
        }
		array[i] = a; 
	}
	file.close();
}