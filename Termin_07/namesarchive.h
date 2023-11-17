#ifndef NAMEARCHIVE_H
#define NAMEARCHIVE_H

// Maximale Namenslänge
#define MAX_NAME_LEN 10

// Maximale Anzahl an Namen
#define MAX_NAMES 100

// Fügt einen Namen hinzu. Im Fehlerfall (Archiv ist voll) soll 0, ansonsten 1 zurückgegeben werden.
// Ist der angegebene Name länger als die zulässige Namenslänge, wird der Name abgeschnitten hinzugefügt. Rückgabe ist dann 1.
int addName(const char *name);
// Wie addName. Fügt Namen aber direkt sortiert hinzu. Voraussetzung ist ein bereits sortiertes Archiv.
int addNameSorted(const char *name); // Gruppe 1
// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeName(const char *name);   // Gruppe 2
// Sortiert die Namen im Archiv aufsteigend.
void sortNames();
// Gibt die Namen zeilenweise aus.
void printNames();
// Leert das Archiv
void clearArchive();

#endif