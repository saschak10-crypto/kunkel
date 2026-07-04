# Hack and Slay – Konzeptdokument

## 1. Vision

Ein actionorientiertes Hack-and-Slay-Spiel aus der 3D-Third-Person-Perspektive, in dem
Spieler:innen sich mit schnellem Nahkampf, ausweichbaren Gegnermustern und
stetig wachsender Charakterstärke durch Horden von Gegnern und Bosskämpfe
kämpfen. Fokus liegt auf befriedigendem, direktem Kampfgefühl ("Game Feel")
und einer klaren Progression von Fähigkeiten und Ausrüstung.

**Kernversprechen:** Wenige, leicht erlernbare Eingaben (Bewegung, Angriff,
Ausweichen, Skill) erzeugen durch Gegner- und Levelvielfalt eine hohe
taktische Tiefe.

## 2. Genre & Referenzen

- Genre: Action-RPG / Hack and Slay (3D Third-Person)
- Referenzen: Diablo (Kampfgefühl reduziert auf Echtzeit-Nahkampf),
  Hades (Raumaufbau, Ausweich-Timing, Meta-Progression),
  Zelda-Dungeons (Raumrätsel light, Schlüssel/Schalter-Mechaniken)

## 3. Zielgruppe

Spieler:innen, die kurze, wiederholbare Sessions (15–30 Minuten) mit
spürbarem Fortschritt schätzen. Zugänglich für Einsteiger, mit Tiefe für
Genre-erfahrene Spieler:innen (Build-Varianten, Schwierigkeitsstufen).

## 4. Setting & Story (Grundgerüst)

Ein grober Rahmen, der Motivation liefert, ohne die Umsetzung zu blockieren:

- **Ort:** Verfallenes Königreich / unterirdische Ruinenanlage ("Die Katakomben
  von Kunkel"), in Zonen mit steigendem Schwierigkeitsgrad unterteilt.
- **Prämisse:** Ein Fluch hat die Bevölkerung in Kreaturen verwandelt; die
  Spielfigur sucht den Ursprung des Fluchs, um ihn zu brechen.
- **Erzählform:** Minimal – kurze Texttafeln zwischen Zonen, Item-Beschreibungen,
  optionale Lore-Objekte. Keine Zwischensequenzen nötig für MVP.

## 5. Kern-Gameplay-Loop

1. Zone betreten → Räume mit Gegnerwellen bereinigen
2. Loot & Erfahrung sammeln
3. Zwischen Räumen: Ausrüstung/Skills anpassen
4. Zonen-Boss besiegen → nächste Zone freischalten
5. Wiederholen mit steigender Schwierigkeit / neuen Gegnertypen

## 6. Spielmechaniken

### 6.1 Bewegung & Steuerung
- Freie 3D-Bewegung mit Third-Person-Kamera, optionalem Lock-On auf Gegner
- Ausweichrolle/-sprint mit kurzer Invulnerabilitätsphase und Cooldown
- Leichter/starker Angriff (Combo-Chain aus 2–3 Treffern)
- Ein aktiver Skill-Slot (später erweiterbar) mit eigenem Cooldown
- Blocken/Parieren optional als späteres Feature (nicht MVP)

### 6.2 Kampf
- Gegner mit klar lesbaren Angriffs-Telegraphen (Vorankündigung vor Trefferwirkung)
- Hit-Stop/Screenshake/Partikel für Treffer-Feedback
- Stagger-System: genug Treffer unterbrechen Gegnerangriffe
- Schadensarten (optional später): physisch / elementar, um Build-Vielfalt zu schaffen

### 6.3 Progression
- Erfahrungspunkte → Charakterlevel → Attributpunkte (Stärke/Vitalität/Tempo)
- Ausrüstung: Waffe, 2 Accessoire-Slots, die Basiswerte und Zusatzeffekte geben
- Skillbaum (klein, MVP: 6–8 Knoten) für aktive/passive Fähigkeiten
- Meta-Progression optional: dauerhafte Boni zwischen Runs (falls Roguelite-Ansatz gewählt wird)

### 6.4 Gegnertypen (Startset für MVP)
| Typ | Verhalten | Rolle |
|---|---|---|
| Läufer | Rennt direkt auf Spieler zu, schwacher Nahkampf | Grundlast, Druck erzeugen |
| Werfer | Hält Abstand, Fernangriff | Zwingt zu Bewegung/Deckung |
| Schildträger | Blockt Angriffe von vorne | Erfordert Flankieren |
| Schwarm | Kleine, schwache Gegner in Gruppen | Flächenschaden belohnen |
| Zonen-Boss | Mehrphasiger Kampf mit Telegraphen-Mustern | Zonen-Abschluss |

### 6.5 Item & Loot
- Droprate steigt mit Gegner-/Raumschwierigkeit
- Seltenheitsstufen (Gewöhnlich/Selten/Episch) mit Farbcodierung
- Kein komplexes Crafting im MVP – Fokus auf Finden & Ausrüsten

## 7. Level-Design-Prinzipien

- Räume als abgeschlossene Kampfarenen (Türen schließen bis Gegner besiegt sind)
- Klare Sichtlinien, keine unfairen Off-Screen-Treffer
- Zonen bestehen aus 6–10 Räumen + 1 Boss-Raum
- Variation durch Raum-Layout-Pools (prozedural kombinierbar oder handdesigned für MVP)

## 8. Technische Grundlage

- **Engine:** Unreal Engine 5 (C++ / Blueprints) – professionelle
  Werkzeugkette, starke Third-Person-/Kampf-Templates, hochwertige
  Grafik-Pipeline (Nanite/Lumen), gute Skalierbarkeit von Prototyp bis
  Vollversion
- **Perspektive:** Umstellung auf 3D Third-Person-Kamera (statt 2D Top-Down),
  da Unreal seine Stärken vor allem im 3D-Bereich ausspielt; die
  Kampf-Mechaniken aus Abschnitt 6 gelten inhaltlich weiter, werden aber
  räumlich in 3D umgesetzt (z.B. Ausweichrolle in Kamerarichtung,
  Lock-On auf Gegner statt reiner 8-Wege-Bewegung)
- **Skriptsprache:** Blueprints für schnelle Iteration, C++ für
  Kernsysteme (Kampf, Statuswerte, KI) sobald Performance/Struktur es
  erfordern
- **Zielplattform MVP:** Desktop (Windows), Konsolen-Export als
  Stretch-Goal (von Unreal nativ unterstützt)

## 9. Art Style & Sound (grobe Richtung)

- Stil: Stilisierte 3D-Optik mit klaren, gut lesbaren Silhouetten (hoher
  Kontrast zwischen Charakteren/Gegnern und Hintergrund) für lesbare
  Gegner-Telegraphen auch in der Third-Person-Ansicht
- Sound: Prägnante, kurze Trefferaudio-Cues; dichte, treibende Musik in
  Kampfräumen, ruhigere Zwischenmusik in sicheren Bereichen

## 10. MVP-Scope (erste spielbare Version)

- 1 Spielfigur mit Bewegung, Angriff-Combo, Ausweichrolle, 1 aktiver Skill
- 3 Gegnertypen (Läufer, Werfer, Schildträger)
- 1 Zone mit 6 Räumen + 1 Boss
- Basis-Progression: Level-Aufstieg + 3 Ausrüstungsgegenstände
- Einfaches HUD: Leben, Ausdauer/Cooldown-Anzeige, Erfahrungsleiste

## 11. Nächste Schritte

1. Unreal-Projekt aufsetzen (UE5, Third-Person-Template als Basis)
2. Projekt-Grundgerüst/Ordnerstruktur anlegen, Test-Level für Prototyping
3. Prototyp: Bewegung + Basisangriff + ein Test-Gegner (Läufer)
4. Playtesting des Kampfgefühls, bevor weitere Systeme aufgebaut werden
