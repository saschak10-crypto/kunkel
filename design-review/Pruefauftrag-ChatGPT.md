# Prüfauftrag für ChatGPT: Design und Fachinhalt der neuen Teil-1-Blöcke

Du prüfst zwei neue Themenblöcke des Lernportals lernen-it.de und das Design der Seiten, auf denen sie erscheinen. Wo du etwas verbesserst, liefere einen Patch gegen das Repo `saschak10-crypto/wiso-lernapp`, Branch `claude/sweet-heisenberg-b2qbz6`.

## Worum es geht

Das Portal ist der Lernweg einer Umschulungsklasse zum Fachinformatiker. Technik: PHP 8.3 ohne Composer, SQLite, eigenes CSS in `public/assets/css/style.css`, Ansichten in `src/Views/`. Neu sind zwei Blöcke im Fach IHK-AP1, Skript `ap1-wissen`:

- `content/subjects/ihk-ap1/ap1-wissen/themenblock-9-gantt-count-distinct-lieferklauseln-kaufoption.json`
- `content/subjects/ihk-ap1/ap1-wissen/themenblock-10-bios-flashback-osi-fehlersuche.json`

Sie schließen Lücken, die der Abgleich mit den IHK-Prüfungen nach AO 2020 als offen gemeldet hat: Gantt-Diagramm selbst zeichnen, `COUNT(DISTINCT)`, Lieferklauseln, Kaufoption beim Leasing, BIOS-Flashback und Fehlersuche entlang der OSI-Schichten.

## Screenshots (lokal aufgenommen, 19.10.2026)

Je Block die Seiten Lernmodus und Reihenfolge, einmal am Desktop (1280 × 900) und einmal am Handy (390 × 844):

- `desktop-gantt-lernmodus.png`, `desktop-gantt-reihenfolge.png`
- `desktop-bios-lernmodus.png`, `desktop-bios-reihenfolge.png`
- `handy-gantt-lernmodus.png`, `handy-gantt-reihenfolge.png`
- `handy-bios-lernmodus.png`, `handy-bios-reihenfolge.png`

## Was mir auf den Screenshots schon aufgefallen ist

Bitte prüfen und, wo es stimmt, beheben:

1. **Schrift der Reihenfolge-Schritte:** Die Schritte sind kleiner und in einer anderen Schrift gesetzt als der übrige Text. Vermutlich erben die Schaltflächen die Schriftart nicht (`font: inherit` fehlt).
2. **Hintergrund endet mitten auf der Seite:** Das Raster und der Farbverlauf hören am Desktop bei etwa 900 px und am Handy bei etwa 890 px auf; darunter ist eine sichtbare Kante. Der Hintergrund scheint an die Fensterhöhe gebunden statt an die Seitenhöhe.
3. **Chat-Knopf verdeckt Inhalt:** Am Handy liegt der runde Chat-Knopf über dem ersten Reihenfolge-Schritt.
4. **Reiter am Handy:** Auf der Reihenfolge-Seite sind am Handy nur „Zusammenfassung“ und „Karteikarten“ zu sehen, die übrigen Reiter fehlen oder liegen unsichtbar außerhalb.
5. **Hauptnavigation am Handy:** Sie ist abgeschnitten („Wied…“), ohne Hinweis, dass man seitlich wischen kann.

## Was du prüfen sollst

**Design:** Lesbarkeit, Abstände, Kontrast (WCAG AA), Darstellung am Handy, Bedienbarkeit per Tastatur und Touch. Nur Änderungen, die das bestehende Erscheinungsbild verbessern, keinen Neuentwurf.

**Fachinhalt der zwei Blöcke:** Stimmen Rechnungen, Paragrafen (§§ 447, 448, 475 Abs. 2 BGB) und Befehle (`ipconfig`, `ping`, `tracert`, `arp -a`, `nslookup`, `Test-NetConnection -Port`)? Ist die Reihenfolge der OSI-Prüfschritte fachlich vertretbar? Ist eine Aufgabe missverständlich?

## Regeln, die du einhalten musst

- **Keinen bestehenden Fragetext umformulieren.** Der Lernfortschritt hängt am Fragetext (`content_key`). Erklärungen, Antwortoptionen und Lehrtexte darfst du ändern.
- **Längenverrat:** Die richtige MC-Antwort darf nicht die längste Option sein.
- **Kein Verräter:** Kein Lückentext enthält seine Antwort; kein Reihenfolge-Schritt verrät seine Position (Wörter wie „zuerst“, „danach“, „zuletzt“).
- **Nichts Unsichtbares referenzieren:** kein „laut Text“, „siehe Abbildung“ ohne Abbildung.
- **Die Lösung darf nie im ausgelieferten HTML stehen.**
- Prüfstand ist `php scripts/selftest.php` (rund vier Minuten, nicht parallel im Browser klicken). Mit lokaler Datenbank (`php scripts/import_content.php`) laufen derzeit 927 Prüfungen grün. Rot sind ohne Claude-Schlüssel immer die zwei Deckel-Prüfungen (HTTP 503), gelegentlich die zufallsabhängige „AP2-Streuung“. Alles andere muss grün bleiben.

## Was ich zurückhaben möchte

1. Eine Liste der Befunde: Datei, Stelle, Problem, Schwere (muss / sollte / kann).
2. Für jeden Befund, den du behebst, den Patch oder die geänderte Datei.
3. Für fachliche Befunde die Quelle oder Begründung.
