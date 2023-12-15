#ifndef NAMEARCHIVE_H
#define NAMEARCHIVE_H

#define MAX_NAME_LEN 100

// Fügt einen Namen hinzu. Im Fehlerfall (kein Speicher mehr) soll 0, ansonsten 1 zurückgegeben werden.
// Der Name soll in beliebiger Länge gespeichert werden können.
// Implementieren Sie die Funktion zunächst ohne Sortierung, anschließend als sortierte Eingabe.
int addName(const char *name);
// Entfernt den angegebenen Namen. Gibt bei Erfolg 1 zurück, ansonsten 0 (Name konnte nicht gefunden werden).
int removeName(const char *name);
// Gibt die Namen zeilenweise aus.
void printNames();
// Leert das Archiv
void clearArchive();
// Lädt den Inhalt einer Textdatei zeilenweise in das Archiv. Gibt 1 bei Erfolg zurück.
int loadArchive(const char *path);
// Speichert das Archiv zeilenweise in einer Textdatei. Gibt 1 bei Erfolg zurück.
int saveArchive(const char *path);

#endif