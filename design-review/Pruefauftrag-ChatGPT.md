# Prüfauftrag: zwei neue Lernblöcke und ihr Design

Du bist Prüfer für ein Lernportal. Alles, was du brauchst, steht in dieser Nachricht und in den 8 angehängten Screenshots. Du brauchst keinen Zugriff auf ein Repository.

## Hintergrund

Das Lernportal lernen-it.de bereitet eine Umschulungsklasse zum Fachinformatiker Systemintegration auf die IHK-Abschlussprüfung Teil 1 vor (Ausbildungsordnung 2020). Technik: PHP 8.3, SQLite, eigenes CSS ohne Framework. Neu sind zwei Themenblöcke, die Lücken aus früheren IHK-Prüfungen schließen:

- **Block 9:** Gantt-Diagramm selbst zeichnen, `COUNT(DISTINCT)`, Lieferklauseln, Kaufoption beim Leasing
- **Block 10:** BIOS-Flashback und Fehlersuche entlang der OSI-Schichten

Jeder Block besteht aus Lehrtexten, 10 Multiple-Choice-Fragen, 10 Karteikarten, 6 Aufgaben, 4 Lückentexten und 1 Reihenfolge-Aufgabe. Der vollständige Inhalt steht unten.

## Deine Aufgabe

### Teil A: Fachliche Prüfung (Schwerpunkt)

Prüfe jeden Lehrtext, jede Frage, Musterlösung und Erklärung auf:

1. **Fachliche Richtigkeit:** Rechnungen nachrechnen, Paragrafen (§§ 447, 448, 475 Abs. 2 BGB, Incoterms 2020) und Befehle (`ipconfig`, `ping`, `tracert`, `arp -a`, `nslookup`, `Test-NetConnection -Port`) prüfen.
2. **Eindeutigkeit:** Gibt es eine MC-Frage mit zwei vertretbaren Antworten? Ist eine Aufgabe missverständlich?
3. **Prüfungsnähe:** Passt Stil und Niveau zu IHK-Teil-1-Aufgaben?
4. **Reihenfolge-Aufgabe in Block 10:** Ist die Abfolge der Prüfschritte fachlich vertretbar?

### Teil B: Design (anhand der Screenshots)

Die Screenshots zeigen je Block den Lernmodus (MC) und die Reihenfolge-Aufgabe, am Desktop (1280 px) und am Handy (390 px). Bekannt sind bereits:

1. **Schrift der Reihenfolge-Schritte:** Die Schritte erscheinen kleiner und in einer anderen Schrift als der übrige Text. Ursache: Die Schaltflächen erben die Schrift nicht. Betroffene Regel:
   ```css
   .reihenfolge-schritt { display: grid; grid-template-columns: 2.25rem 1fr; align-items: center; gap: 0.75rem; width: 100%; min-height: 3.25rem; padding: 0.65rem 0.8rem; border: 2px solid var(--border); border-radius: 0.75rem; background: var(--panel-2); color: var(--text); text-align: left; cursor: pointer; }
   ```
2. **Chat-Knopf verdeckt Inhalt am Handy:** Der runde Knopf liegt über dem ersten Reihenfolge-Schritt.
   ```css
   .ki-chat { position: fixed; right: 1.25rem; bottom: 1.25rem; z-index: 80; }
   .ki-chat-toggle { width: 3.2rem; height: 3.2rem; border-radius: 50%; /* … */ }
   ```
3. **Wischbare Leisten ohne Hinweis am Handy:** Hauptnavigation und Reiterleiste („Zusammenfassung, Karteikarten, …“) sind absichtlich einzeilig und seitlich wischbar, zeigen aber nicht, dass rechts noch mehr kommt (die Navigation endet abgeschnitten bei „Wied…“).
   ```css
   @media (max-width: 700px) {
       .lernwege { flex-wrap: nowrap; overflow-x: auto; -webkit-overflow-scrolling: touch; scrollbar-width: thin; padding-bottom: 0.4rem; margin-bottom: 1rem; }
       .lernweg { flex: 0 0 auto; white-space: nowrap; }
   }
   ```

**Kein Fehler, bitte nicht beheben:** Auf den ganzseitigen Screenshots endet das Hintergrundraster bei etwa 900 px. Das ist ein Effekt der Aufnahme: Der Hintergrund ist mit `position: fixed` an das Fenster gebunden und wird im Browser beim Scrollen immer mitgezeigt.

Schau zusätzlich nach Kontrast (WCAG AA), Abständen, Lesbarkeit und Bedienbarkeit per Touch. Kein Neuentwurf, nur Verbesserungen im bestehenden Stil (dunkles Design, Cyan als Akzent).

## Regeln für deine Vorschläge

- **Fragetexte nicht umformulieren.** Der Lernfortschritt hängt am Wortlaut der Frage. Antwortoptionen, Erklärungen, Lehrtexte und Musterlösungen darfst du ändern.
- **Bei MC-Fragen darf die richtige Antwort nicht die längste Option sein.** Sonst erkennt man sie an der Länge.
- **Kein Lückentext darf seine Antwort enthalten**, und kein Reihenfolge-Schritt darf seine Position verraten (Wörter wie „zuerst“, „danach“, „zuletzt“).
- **Nichts Unsichtbares referenzieren**, etwa „laut Text“ oder „siehe Abbildung“.

## So möchte ich das Ergebnis

1. **Befundliste als Tabelle:** Nr. · Block · Stelle (z. B. „MC 4“, „Aufgabe 2“, „Lehrtext Lieferklauseln“) · Problem · Schwere (muss / sollte / kann) · Vorschlag mit genauem neuen Wortlaut.
2. **Für Design-Befunde:** fertige CSS-Regeln zum Einfügen.
3. **Für fachliche Befunde:** kurze Begründung oder Quelle.
4. **Wenn alles stimmt,** schreib das ausdrücklich, statt Befunde zu erfinden.

---

# Inhalt der beiden Blöcke

## Block 9: Planen, zählen, einkaufen: Gantt-Diagramm, COUNT(DISTINCT), Lieferklauseln und Kaufoption

**Situation:** Die Westerwald Medientechnik GmbH in Montabaur stattet die Stadtbücherei Diez mit neuen Ausleihplätzen aus. Du sollst den Zeitplan als Gantt-Diagramm aufstellen, aus der Einsatzdatenbank zählen, wie viele Kunden und Techniker beteiligt waren, die Lieferbedingungen des Großhändlers prüfen und dem Kunden den Leasingvertrag mit Kaufoption erklären. Dein Ausbilder sagt: „Das sind vier kleine Themen, die in Teil 1 immer wieder Punkte kosten.“

**Leitfrage:** Wie zeichnest du aus einer Vorgangsliste ein Gantt-Diagramm, was zählen COUNT(*), COUNT(spalte) und COUNT(DISTINCT spalte), wer trägt bei welcher Lieferklausel die Kosten, und was kostet ein Leasing mit Kaufoption im Vergleich zum Kauf?

**Lernziele:**
- Aus einer Vorgangsliste mit Dauer und Vorgängern Anfang und Ende jedes Vorgangs bestimmen und als Balken eintragen
- Den kritischen Pfad und den Puffer eines Vorgangs aus dem Gantt-Diagramm ablesen
- COUNT(*), COUNT(spalte) und COUNT(DISTINCT spalte) unterscheiden und das Ergebnis an einer Tabelle vorhersagen
- Lieferklauseln wie ab Werk, unfrei, frachtfrei und frei Haus den Versandkosten zuordnen und den Gefahrübergang benennen
- Leasing, Kaufoption, Andienungsrecht und Mietkauf unterscheiden
- Die Gesamtkosten eines Leasings mit Kaufoption berechnen und mit dem Kauf vergleichen

### Lehrtexte

**Ein Gantt-Diagramm selbst zeichnen**

Ein Gantt-Diagramm (Balkenplan) zeigt jeden Vorgang als waagerechten Balken über einer Zeitachse. Grundlage ist eine Vorgangsliste mit Nummer, Bezeichnung, Dauer und Vorgängern. Du gehst in vier Schritten vor. Erstens: Zeitachse in Arbeitstagen anlegen, Tag 1 links. Zweitens: Vorgänge ohne Vorgänger beginnen an Tag 1. Drittens: Jeder andere Vorgang beginnt am Tag nach dem spätesten Ende seiner Vorgänger (Normalfolge Ende–Anfang). Viertens: Ende = Anfang + Dauer − 1, denn der Anfangstag zählt mit. Beispiel: A Anforderungen 3 Tage, B Hardware bestellen 5 Tage nach A, C Software vorbereiten 4 Tage nach A, D Installation 2 Tage nach B und C. A läuft von Tag 1 bis 3, B von 4 bis 8, C von 4 bis 7, D beginnt erst nach dem späteren Ende, also nach Tag 8, und läuft von Tag 9 bis 10. Ein Meilenstein hat die Dauer null und wird als Raute am Ende seines Vorgängers eingezeichnet, etwa „Abnahme“ an Tag 10. Abhängigkeiten zeichnet man als Pfeil vom Ende des Vorgängers zum Anfang des Nachfolgers.

**Kritischer Pfad und Puffer im Gantt-Diagramm**

Der kritische Pfad ist die Kette von Vorgängen ohne Puffer: Verzögert sich einer davon um einen Tag, verschiebt sich das Projektende um einen Tag. Im Beispiel ist das A – B – D, zusammen 10 Tage. C endet an Tag 7, D braucht C aber erst ab Tag 9. C kann sich also um einen Tag verspäten, ohne dass D später beginnt: C hat einen Puffer von einem Tag. Puffer = spätester erlaubter Endtag − tatsächlicher Endtag. Der späteste erlaubte Endtag ist der Tag vor dem Anfang des Nachfolgers. Im Diagramm markiert man den kritischen Pfad farbig und zeichnet den Puffer als gestrichelte Verlängerung hinter dem Balken. Ein Gantt-Diagramm zeigt die Termine anschaulich, die Abhängigkeiten aber nur über die Pfeile; der Netzplan zeigt sie deutlicher, der Balkenplan ist dafür für Kunden und Beteiligte leichter zu lesen.

**Zählen in SQL: COUNT(*), COUNT(spalte), COUNT(DISTINCT spalte)**

Die Aggregatfunktion COUNT zählt Zeilen, aber je nach Schreibweise verschiedene. COUNT(*) zählt alle Zeilen, auch solche mit NULL-Werten. COUNT(spalte) zählt nur die Zeilen, in denen diese Spalte nicht NULL ist. COUNT(DISTINCT spalte) zählt die verschiedenen Werte dieser Spalte, NULL zählt nicht mit. Beispiel Tabelle tickets mit sechs Zeilen: Kunde Bauer mit Technikerin Kaya, Bauer ohne Techniker, Schmitt mit Kaya, Klein mit Lenz, Schmitt ohne Techniker, Bauer mit Lenz. Dann ergibt SELECT COUNT(*) FROM tickets 6, COUNT(techniker) 4, COUNT(DISTINCT techniker) 2 und COUNT(DISTINCT kunde) 3. Mit GROUP BY zählt COUNT je Gruppe: SELECT kunde, COUNT(DISTINCT techniker) FROM tickets GROUP BY kunde liefert Bauer 2, Klein 1 und Schmitt 1. Typischer Prüfungsfehler: „Wie viele verschiedene Kunden?“ mit COUNT(kunde) beantworten — das zählt Tickets, nicht Kunden.

**Lieferklauseln: Wer zahlt den Versand?**

Ohne Vereinbarung trägt der Verkäufer die Kosten der Übergabe, etwa für Verpackung, Messen und Wiegen, der Käufer die Kosten der Abnahme und Versendung (§ 448 BGB). Lieferklauseln verteilen die Versandkosten anders. Sie bestehen aus drei Teilen: Rollgeld beim Verkäufer bis zur Versandstation, Fracht bis zur Empfangsstation und Rollgeld bis zum Käufer. „Ab Werk“ oder „ab Lager“: Der Käufer trägt alle drei. „Unfrei“ oder „ab hier“: Der Verkäufer zahlt das Rollgeld bis zur Versandstation, der Käufer Fracht und Rollgeld am Zielort. „Frachtfrei“ oder „frei dort“: Der Verkäufer zahlt Rollgeld und Fracht, der Käufer nur das Rollgeld am Zielort. „Frei Haus“ oder „frei Lager“: Der Verkäufer trägt alles. Im Auslandsgeschäft gelten die Incoterms 2020, etwa EXW (ab Werk, Käufer trägt fast alles) bis DDP (geliefert verzollt, Verkäufer trägt alles einschließlich Einfuhrabgaben).

**Gefahrübergang beim Versendungskauf**

Von den Kosten zu trennen ist die Frage, wer das Risiko trägt, wenn die Ware unterwegs beschädigt wird oder verloren geht. Beim Versendungskauf zwischen Unternehmen geht die Gefahr auf den Käufer über, sobald der Verkäufer die Ware an den Spediteur oder Paketdienst übergeben hat (§ 447 BGB). Der Käufer muss dann zahlen, auch wenn die Ware beschädigt ankommt, und hält sich an den Transporteur. Beim Verbrauchsgüterkauf, also Unternehmer an Verbraucher, gilt das grundsätzlich nicht: Die Gefahr geht erst mit der Übergabe an den Verbraucher über (§ 475 Abs. 2 BGB). Eine Klausel wie „frei Haus“ regelt nur die Kosten, nicht automatisch die Gefahr. Wer beides beim Verkäufer lassen will, muss das ausdrücklich vereinbaren oder eine Incoterms-Klausel wählen, die beides festlegt.

**Leasing, Kaufoption, Andienungsrecht und Mietkauf**

Beim Leasing kauft der Leasinggeber das Gerät und überlässt es dem Leasingnehmer gegen monatliche Raten zur Nutzung. Eigentümer bleibt der Leasinggeber. Am Vertragsende gibt es drei Wege: Rückgabe, Verlängerung oder Kauf zum vereinbarten Restwert. Eine Kaufoption ist ein Recht des Leasingnehmers, keine Pflicht: Er darf kaufen, muss aber nicht. Beim Andienungsrecht ist es umgekehrt: Der Leasinggeber darf verlangen, dass der Leasingnehmer zum Restwert kauft. Beim Mietkauf werden die Raten auf den Kaufpreis angerechnet, und das Eigentum geht am Ende über. Gesamtkosten Leasing mit Kaufoption = Sonderzahlung + Rate × Laufzeit in Monaten + Restwert. Beispiel: 1.000 € Sonderzahlung, 36 Raten zu 250 € und 1.200 € Restwert ergeben 1.000 + 9.000 + 1.200 = 11.200 €. Leasing schont die Liquidität, weil kein Kaufpreis auf einmal fällig wird, und erleichtert den Austausch gegen neue Technik. Insgesamt ist es meist teurer als ein Barkauf, und der Vertrag bindet über die ganze Laufzeit.

### Multiple Choice (richtige Antwort mit ✔ markiert)

1. Vorgang D hat die Vorgänger B (Ende Tag 8) und C (Ende Tag 7). An welchem Tag beginnt D?
   - An Tag 8, direkt mit dem Ende von B
   - ✔ An Tag 9, nach dem späteren Ende
   - An Tag 8, nach dem früheren Ende
   - An Tag 16, nach der Summe beider
   - Erklärung: Ein Nachfolger beginnt am Tag nach dem spätesten Ende aller Vorgänger. B endet an Tag 8, also beginnt D an Tag 9.

2. Ein Vorgang beginnt an Tag 4 und dauert 5 Tage. An welchem Tag endet er?
   - An Tag 9
   - An Tag 10
   - ✔ An Tag 8
   - An Tag 5
   - Erklärung: Ende = Anfang + Dauer − 1, weil der Anfangstag mitzählt: 4 + 5 − 1 = 8.

3. Wie wird ein Meilenstein im Gantt-Diagramm dargestellt?
   - Als Balken mit der Länge eines Tages
   - Als gestrichelter Balken hinter dem Vorgang
   - ✔ Als Raute mit der Dauer null am Ende
   - Als Pfeil zwischen zwei Vorgängen
   - Erklärung: Ein Meilenstein ist ein Ereignis mit der Dauer null, etwa die Abnahme, und wird als Raute eingezeichnet.

4. Woran erkennst du im Gantt-Diagramm den kritischen Pfad?
   - Die Vorgänge mit der größten Zahl von Mitarbeitern
   - ✔ Die Kette der Vorgänge ohne zeitlichen Puffer
   - Die Vorgänge mit den höchsten Kosten im Projekt
   - Die Vorgänge, die zuerst beginnen dürfen
   - Erklärung: Jede Verzögerung eines Vorgangs auf dem kritischen Pfad verschiebt das Projektende.

5. Die Tabelle tickets hat 6 Zeilen, in 2 davon ist die Spalte techniker NULL. Was liefert COUNT(techniker)?
   - 6, weil COUNT alle Zeilen zählt
   - 2, weil nur NULL-Zeilen zählen
   - 8, weil NULL doppelt zählt
   - ✔ 4, weil NULL nicht mitzählt
   - Erklärung: COUNT(spalte) zählt nur Zeilen, in denen die Spalte einen Wert hat. COUNT(*) dagegen ergäbe 6.

6. Mit welcher Abfrage ermittelst du, wie viele verschiedene Kunden in der Tabelle tickets vorkommen?
   - ✔ SELECT COUNT(DISTINCT kunde) FROM tickets
   - SELECT COUNT(kunde) FROM tickets
   - SELECT DISTINCT COUNT(*) FROM tickets
   - SELECT COUNT(kunde) FROM tickets GROUP BY kunde
   - Erklärung: Nur COUNT(DISTINCT kunde) zählt jeden Kunden einmal. COUNT(kunde) zählt die Tickets mit eingetragenem Kunden.

7. Bei welcher Lieferklausel zahlt der Käufer nur das Rollgeld vom Zielbahnhof bis zu sich?
   - Ab Werk
   - Frei Lager
   - Unfrei
   - ✔ Frachtfrei
   - Erklärung: „Frachtfrei“ heißt: Der Verkäufer trägt Rollgeld bis zur Versandstation und die Fracht, der Käufer das Rollgeld am Zielort.

8. Ein Händler versendet einen Drucker per Spedition an ein Unternehmen. Unterwegs wird er beschädigt. Wer trägt die Gefahr ohne besondere Vereinbarung?
   - Der Händler bis zur Übergabe an den Käufer
   - Die Spedition in jedem Fall allein
   - ✔ Der Käufer ab Übergabe an die Spedition
   - Händler und Käufer je zur Hälfte
   - Erklärung: Beim Versendungskauf zwischen Unternehmen geht die Gefahr mit der Übergabe an die Transportperson über (§ 447 BGB).

9. Was unterscheidet die Kaufoption vom Andienungsrecht beim Leasing?
   - Die Kaufoption gilt für Fahrzeuge, das Andienungsrecht für IT
   - ✔ Kaufoption: Leasingnehmer entscheidet; Andienung: Leasinggeber
   - Die Kaufoption verpflichtet zum Kauf, das Andienungsrecht nicht
   - Beide bedeuten dasselbe und sind nur verschieden benannt
   - Erklärung: Die Kaufoption ist ein Recht des Leasingnehmers. Beim Andienungsrecht kann der Leasinggeber den Kauf zum Restwert verlangen.

10. Wer ist während der Laufzeit eines Leasingvertrags Eigentümer des Servers?
   - Der Leasingnehmer ab der ersten Rate
   - Der Hersteller bis zum Ende der Garantie
   - ✔ Der Leasinggeber, bis ein Kauf erfolgt
   - Der Leasingnehmer nach der Sonderzahlung
   - Erklärung: Der Leasinggeber kauft das Gerät und bleibt Eigentümer. Erst ein Kauf am Ende überträgt das Eigentum.

### Karteikarten

- **Gantt-Diagramm — Ende eines Vorgangs berechnen?** → Ende = Anfang + Dauer − 1, weil der Anfangstag mitzählt.
- **Wann beginnt ein Vorgang mit mehreren Vorgängern?** → Am Tag nach dem spätesten Ende aller Vorgänger.
- **Meilenstein im Balkenplan?** → Ereignis mit Dauer null, eingezeichnet als Raute, etwa die Abnahme.
- **Puffer eines Vorgangs?** → Spätester erlaubter Endtag − tatsächlicher Endtag; der späteste erlaubte Endtag ist der Tag vor dem Anfang des Nachfolgers.
- **COUNT(*) gegen COUNT(spalte)?** → COUNT(*) zählt alle Zeilen, COUNT(spalte) nur Zeilen, in denen die Spalte nicht NULL ist.
- **COUNT(DISTINCT spalte)?** → Zählt die verschiedenen Werte der Spalte; NULL zählt nicht mit.
- **Lieferklausel „unfrei“ — wer zahlt was?** → Verkäufer: Rollgeld bis zur Versandstation. Käufer: Fracht und Rollgeld am Zielort.
- **Lieferklausel „ab Werk“ und „frei Haus“?** → Ab Werk: Käufer trägt alle Versandkosten. Frei Haus: Verkäufer trägt alle Versandkosten.
- **Gefahrübergang beim Versendungskauf?** → Zwischen Unternehmen mit Übergabe an die Transportperson (§ 447 BGB); an Verbraucher erst mit Übergabe an den Verbraucher (§ 475 Abs. 2 BGB).
- **Gesamtkosten Leasing mit Kaufoption?** → Sonderzahlung + Rate × Laufzeit in Monaten + Restwert.

### Aufgaben

**Aufgabe 1** (6 Punkte, Freitext)

Für die Ausleihplätze der Stadtbücherei Diez liegt diese Vorgangsliste vor (Dauer in Arbeitstagen): A Bestandsaufnahme, 2 Tage, kein Vorgänger. B Konzept, 3 Tage, nach A. C Geräte bestellen und liefern lassen, 6 Tage, nach B. D Personal schulen, 2 Tage, nach B. E Geräte einrichten, 4 Tage, nach C. F Übergabe, 1 Tag, nach D und E. Gib für jeden Vorgang den Anfangs- und Endtag an, so wie du die Balken im Gantt-Diagramm einzeichnen würdest, und nenne die Projektdauer.

Musterlösung: A: Tag 1 bis 2. B: Tag 3 bis 5. C: Tag 6 bis 11. D: Tag 6 bis 7. E: Tag 12 bis 15. F beginnt nach dem späteren Ende von D (Tag 7) und E (Tag 15), also Tag 16 bis 16. Die Projektdauer beträgt 16 Arbeitstage.

Stichwörter: 11, 15, 16, Arbeitstage

**Aufgabe 2** (5 Punkte, Freitext)

Nimm die Vorgangsliste der Stadtbücherei aus der vorigen Aufgabe: A 2 Tage; B 3 Tage nach A; C 6 Tage nach B; D 2 Tage nach B; E 4 Tage nach C; F 1 Tag nach D und E. Bestimme den kritischen Pfad, berechne den Puffer von Vorgang D und erkläre, was eine Verspätung der Lieferung (Vorgang C) um zwei Tage bewirkt.

Musterlösung: Kritischer Pfad: A – B – C – E – F mit 2 + 3 + 6 + 4 + 1 = 16 Tagen. D endet an Tag 7, F beginnt an Tag 16; D dürfte also bis Tag 15 enden. Puffer von D: 15 − 7 = 8 Tage. C liegt auf dem kritischen Pfad und hat keinen Puffer: Zwei Tage Verspätung verschieben E, F und das Projektende um zwei Tage auf Tag 18.

Stichwörter: kritischer Pfad, 8 Tage, Puffer, 18

**Aufgabe 3** (4 Punkte, Freitext)

Die Tabelle einsaetze der Westerwald Medientechnik GmbH hat die Spalten einsatz_nr, kunde und techniker und enthält sieben Zeilen: 1 Bauer GmbH, Kaya · 2 Weber KG, NULL · 3 Bauer GmbH, Lenz · 4 Lahn AG, Kaya · 5 Weber KG, Kaya · 6 Bauer GmbH, NULL · 7 Lahn AG, Lenz. Gib die Ergebnisse von COUNT(*), COUNT(techniker), COUNT(DISTINCT techniker) und COUNT(DISTINCT kunde) an und begründe jeweils kurz.

Musterlösung: COUNT(*) = 7, weil alle Zeilen zählen. COUNT(techniker) = 5, weil die zwei Zeilen mit NULL nicht zählen. COUNT(DISTINCT techniker) = 2, denn es gibt nur Kaya und Lenz; NULL zählt nicht als Wert. COUNT(DISTINCT kunde) = 3, nämlich Bauer GmbH, Weber KG und Lahn AG.

Stichwörter: 7, 5, NULL, Kaya, Lenz

**Aufgabe 4** (5 Punkte, Freitext)

Mit derselben Tabelle einsaetze (Spalten einsatz_nr, kunde, techniker) soll für jeden Kunden ausgegeben werden, wie viele verschiedene Techniker bei ihm waren, sortiert nach Kundenname. Schreib die SQL-Abfrage und nenne das Ergebnis für die sieben Zeilen: 1 Bauer GmbH, Kaya · 2 Weber KG, NULL · 3 Bauer GmbH, Lenz · 4 Lahn AG, Kaya · 5 Weber KG, Kaya · 6 Bauer GmbH, NULL · 7 Lahn AG, Lenz.

Musterlösung: SELECT kunde, COUNT(DISTINCT techniker) AS anzahl_techniker FROM einsaetze GROUP BY kunde ORDER BY kunde; Ergebnis: Bauer GmbH 2 (Kaya, Lenz), Lahn AG 2 (Kaya, Lenz), Weber KG 1 (Kaya; der Einsatz ohne Techniker zählt nicht).

Stichwörter: DISTINCT, GROUP BY, ORDER BY, Weber

**Aufgabe 5** (6 Punkte, Freitext)

Der Großhändler liefert die Geräte für die Stadtbücherei per Bahn. Die Versandkosten setzen sich so zusammen: 40 € Rollgeld vom Lager des Großhändlers zum Versandbahnhof, 180 € Fracht, 35 € Rollgeld vom Zielbahnhof zur Westerwald Medientechnik GmbH. Berechne, welchen Betrag die Westerwald Medientechnik GmbH als Käufer bei den Klauseln „ab Werk“, „unfrei“, „frachtfrei“ und „frei Haus“ trägt. Nenne außerdem, wer das Risiko trägt, wenn die Geräte unterwegs beschädigt werden.

Musterlösung: Ab Werk: 40 + 180 + 35 = 255 €. Unfrei: Fracht und Rollgeld am Zielort, 180 + 35 = 215 €. Frachtfrei: nur das Rollgeld am Zielort, 35 €. Frei Haus: 0 €, der Großhändler trägt alles. Risiko: Beide sind Unternehmen; beim Versendungskauf geht die Gefahr mit der Übergabe an die Bahn auf den Käufer über (§ 447 BGB), unabhängig davon, wer die Kosten trägt, sofern nichts anderes vereinbart ist.

Stichwörter: 255 €, 215 €, 35 €, 0 €, § 447

**Aufgabe 6** (6 Punkte, Freitext)

Die Stadtbücherei Diez möchte einen Server nicht kaufen, sondern leasen. Kaufpreis: 12.000 €. Leasingangebot: 1.200 € Sonderzahlung, 36 Monatsraten zu 290 €, Kaufoption am Ende zum Restwert von 1.500 €. Berechne die Gesamtkosten des Leasings mit Ausübung der Kaufoption und die Mehrkosten gegenüber dem Kauf. Nenne je einen Vorteil und einen Nachteil des Leasings für die Bücherei.

Musterlösung: Raten: 36 × 290 € = 10.440 €. Gesamtkosten mit Kaufoption: 1.200 € + 10.440 € + 1.500 € = 13.140 €. Mehrkosten gegenüber dem Kauf: 13.140 € − 12.000 € = 1.140 €. Vorteil: Die Liquidität wird geschont, weil der Kaufpreis nicht auf einmal fällig wird; nach der Laufzeit kann auch auf ein neues Gerät gewechselt werden. Nachteil: insgesamt teurer, und der Vertrag bindet 36 Monate; bis zum Kauf gehört der Server dem Leasinggeber.

Stichwörter: 10.440 €, 13.140 €, 1.140 €, Liquidität

### Lückentexte

- Im Gantt-Diagramm endet ein Vorgang, der an Tag 4 beginnt und 3 Tage dauert, an Tag [[1]], weil der Anfangstag mitzählt.  → Antworten: 6 / sechs
- Um jeden Wert einer Spalte nur einmal zu zählen, schreibt man in der Klammer von COUNT vor den Spaltennamen das Schlüsselwort [[1]].  → Antworten: DISTINCT / distinct
- Trägt der Verkäufer Rollgeld, Fracht und die Zustellung bis zum Käufer, lautet die Lieferklausel „frei [[1]]“.  → Antworten: Haus / Lager
- Darf der Leasingnehmer am Ende der Laufzeit zum Restwert kaufen, ohne dazu verpflichtet zu sein, hat er eine [[1]].  → Antworten: Kaufoption / Kauf-Option

### Reihenfolge (hier in richtiger Reihenfolge; im Portal gemischt)

Du sollst für die Stadtbücherei Diez aus der Vorgangsliste ein Gantt-Diagramm zeichnen. Bring die Arbeitsschritte in die richtige Reihenfolge.

1. Vorgänge mit Dauer und Vorgängern aus der Liste übernehmen
2. Zeitachse in Arbeitstagen anlegen
3. Vorgänge ohne Vorgänger an Tag 1 beginnen lassen
4. Jeden Nachfolger nach dem spätesten Ende seiner Vorgänger einzeichnen
5. Meilensteine als Raute ohne Dauer setzen
6. Kritischen Pfad markieren und Puffer gestrichelt eintragen

Erklärung: Erst die Daten, dann die Achse, dann die Balken in Abhängigkeitsfolge. Kritischer Pfad und Puffer ergeben sich erst, wenn alle Balken stehen.


---

## Block 10: Fehler finden: BIOS-Flashback und Fehlersuche entlang der OSI-Schichten

**Situation:** Bei der Lahnwerk Metallbau GmbH in Limburg gibt es zwei Störungen. Ein neu zusammengebauter Konstruktionsrechner zeigt nach dem Einschalten kein Bild, die Debug-LED für die CPU leuchtet. Und im Büro kann ein Mitarbeiter die Intranetseite nicht öffnen, obwohl sein Rechner „am Netz hängt“. Deine Ausbilderin sagt: „Rate nicht. Geh systematisch vor und schreib auf, was du geprüft hast.“

**Leitfrage:** Wann und wie spielst du eine Firmware per BIOS-Flashback ein, und wie grenzt du eine Netzwerkstörung Schicht für Schicht ein, bis die Ursache feststeht?

**Lernziele:**
- Erklären, warum eine neue CPU auf einem Mainboard mit alter Firmware kein Bild liefern kann
- Die Voraussetzungen und Schritte eines BIOS-Flashbacks nennen und vom Update im laufenden UEFI unterscheiden
- Risiken eines Firmware-Updates benennen und Gegenmaßnahmen angeben
- Eine Netzwerkstörung von unten nach oben entlang der OSI-Schichten eingrenzen
- Jedem Prüfschritt das passende Werkzeug zuordnen, etwa Link-LED, ipconfig, ping, Test-NetConnection und nslookup
- Aus einer Reihe von Befunden die fehlerhafte Schicht und die Ursache ableiten

### Lehrtexte

**Warum eine neue CPU kein Bild liefern kann**

Die Firmware des Mainboards (UEFI, umgangssprachlich BIOS) initialisiert beim Start Prozessor, Arbeitsspeicher und Grafik. Sie muss den Prozessor kennen, sonst bricht der Start ab, bevor ein Bild erscheint. Mainboards liegen oft monatelang im Lager; die ausgelieferte Firmware ist dann älter als die neueste Prozessorgeneration, die der Sockel laut Hersteller unterstützt. Typisches Bild: Lüfter drehen, aber der Monitor bleibt schwarz, und die Debug-LED „CPU“ leuchtet dauerhaft. Bevor man ein Firmware-Update ansetzt, prüft man die Kompatibilitätsliste des Herstellers (CPU-Support-Liste): Ab welcher Firmware-Version wird dieser Prozessor unterstützt? Erst wenn das feststeht, ist das Update die Lösung — sonst sucht man an der falschen Stelle, etwa bei einem nicht eingerasteten RAM-Riegel oder einem fehlenden 8-poligen CPU-Stromstecker.

**BIOS-Flashback: Firmware ohne lauffähiges System einspielen**

Ein normales Firmware-Update startet man im UEFI selbst, zum Beispiel über ein eingebautes Update-Werkzeug. Das setzt ein startfähiges System voraus — genau das fehlt, wenn die Firmware den Prozessor nicht kennt. Viele Mainboards haben dafür eine Notfunktion, die je nach Hersteller anders heißt, etwa USB BIOS FlashBack, Flash BIOS Button oder Q-Flash Plus. Sie spielt die Firmware von einem USB-Stick ein, ohne dass Prozessor, Arbeitsspeicher oder Grafikkarte arbeiten müssen. Ablauf: Firmware für das exakte Mainboard-Modell von der Herstellerseite laden, nach Vorgabe des Herstellers umbenennen, auf einen FAT32-formatierten Stick kopieren, Stick in den markierten USB-Anschluss stecken, Netzteil mit 24-poligem und CPU-Stecker anschließen, Taste drücken, bis die LED blinkt, und warten, bis sie erlischt. Danach startet man normal und lädt im UEFI die Standardeinstellungen.

**Risiken eines Firmware-Updates und Gegenmaßnahmen**

Ein abgebrochenes Firmware-Update kann das Mainboard unbrauchbar machen, weil dann keine startfähige Firmware mehr vorhanden ist. Gegenmaßnahmen: Strom während des Vorgangs nicht unterbrechen, bei Arbeitsplätzen mit unsicherer Versorgung eine USV verwenden, nur die Datei für das exakte Modell und die exakte Revision nehmen, Prüfsumme vergleichen, wenn der Hersteller eine angibt. Manche Mainboards haben zwei Firmware-Chips (Dual-BIOS) und können von der Sicherung starten. Ein Update ist kein Routinevorgang: Man spielt es ein, wenn es einen Grund gibt, etwa Prozessorunterstützung, eine geschlossene Sicherheitslücke oder einen behobenen Fehler. Nach dem Update sind eigene Einstellungen oft zurückgesetzt, etwa Startreihenfolge, Speicherprofil, Virtualisierung oder Secure Boot. Sie werden geprüft und dokumentiert. Zum Zurücksetzen der Einstellungen ohne Update dient der CMOS-Reset per Jumper, Taste oder kurzzeitig entnommener Knopfzelle.

**Fehlersuche entlang der OSI-Schichten**

Bei einer Netzwerkstörung prüft man nicht wahllos, sondern Schicht für Schicht. Am häufigsten ist der Weg von unten nach oben (Bottom-up): Erst wenn eine Schicht nachweislich funktioniert, prüft man die nächste. Schicht 1, Bitübertragung: Steckt das Kabel, leuchtet die Link-LED an Rechner und Switch, ist die Dose gepatcht? Schicht 2, Sicherung: Ist der Switchport aktiv und im richtigen VLAN, kennt der Rechner die MAC-Adresse des Gateways (arp -a)? Schicht 3, Vermittlung: Stimmen IP-Adresse, Maske und Standardgateway (ipconfig /all), antwortet das Gateway auf ping, kommt man mit tracert bis zum Ziel? Schicht 4, Transport: Ist der benötigte Port erreichbar, oder sperrt eine Firewall (Test-NetConnection ziel -Port 443)? Schichten 5 bis 7: Löst der Name auf (nslookup), läuft der Dienst, stimmen Zertifikat und Anmeldung? Wer bei einem Fehler oben beginnt, nennt das Top-down; bei einem klaren Hinweis kann man auch in der Mitte mit ping einsteigen und je nach Ergebnis nach oben oder unten gehen.

**Befunde richtig lesen**

Jeder Befund sagt etwas über die Schichten darunter. Antwortet das Gateway auf ping, funktionieren Schicht 1 bis 3 im eigenen Netz; Kabel und VLAN muss man dann nicht mehr prüfen. Klappt der Zugriff über die IP-Adresse, aber nicht über den Namen, liegt der Fehler in der Namensauflösung, also bei DNS. Zeigt ipconfig eine Adresse aus 169.254.0.0/16, hat der Rechner keine Antwort von einem DHCP-Server bekommen und sich selbst eine APIPA-Adresse gegeben; dann prüft man Kabel, VLAN und DHCP-Server. Ein ping kann auch scheitern, weil eine Firewall ICMP sperrt, obwohl der Dienst erreichbar ist; deshalb prüft man den Dienstport zusätzlich mit Test-NetConnection. Jeder Prüfschritt wird mit Befehl und Ergebnis notiert, damit Kolleginnen den Stand übernehmen können und das Ticket nachvollziehbar bleibt.

**Werkzeuge der Fehlersuche unter Windows**

ipconfig /all zeigt IP-Adresse, Maske, Gateway, DNS-Server und ob die Adresse per DHCP kam. ipconfig /renew fordert eine neue Adresse an, ipconfig /flushdns leert den Namenszwischenspeicher. ping prüft mit ICMP, ob ein Ziel antwortet, und zeigt die Laufzeit. tracert zeigt die Router auf dem Weg zum Ziel und damit, wo eine Verbindung abbricht. arp -a zeigt, welche MAC-Adressen der Rechner zu IP-Adressen im eigenen Netz kennt. nslookup fragt einen DNS-Server nach einem Namen und zeigt, welcher Server geantwortet hat. Test-NetConnection in der PowerShell prüft mit -Port, ob ein TCP-Port erreichbar ist, etwa 443 für HTTPS. netstat -an listet offene Verbindungen und lauschende Ports auf dem eigenen Rechner. Am Switch zeigen Port-LEDs und die Verwaltungsoberfläche Linkstatus, VLAN und Fehlerzähler.

### Multiple Choice (richtige Antwort mit ✔ markiert)

1. Ein neuer Rechner zeigt kein Bild, die Debug-LED „CPU“ leuchtet. Der Prozessor ist neuer als das Mainboard. Was prüfst du zuerst?
   - Ob der Monitor auf den richtigen Eingang gestellt ist
   - Ob die Grafikkarte im obersten Steckplatz sitzt
   - ✔ Ob die Firmware den Prozessor schon unterstützt
   - Ob das Betriebssystem auf der SSD aktiviert ist
   - Erklärung: Die Firmware muss den Prozessor kennen. Die CPU-Support-Liste nennt die Firmware-Version, ab der er unterstützt wird.

2. Was unterscheidet einen BIOS-Flashback von einem Firmware-Update im UEFI?
   - ✔ Der Flashback braucht kein startfähiges System
   - Der Flashback lädt die Firmware immer direkt aus dem Internet
   - Der Flashback setzt ein installiertes Betriebssystem voraus
   - Der Flashback ändert nur die Einstellungen, nicht die Firmware
   - Erklärung: Die Notfunktion spielt die Datei vom USB-Stick ein, ohne dass das System starten muss. Dafür genügen Strom, Stick und Taste.

3. Welches Dateisystem verlangen Mainboards in der Regel für den Stick beim BIOS-Flashback?
   - NTFS
   - exFAT
   - ext4
   - ✔ FAT32
   - Erklärung: Die Notfunktion liest nur einfache Dateisysteme; die Herstelleranleitungen nennen FAT32.

4. Warum darf während eines Firmware-Updates der Strom nicht ausfallen?
   - Weil sonst die Einstellungen in der Knopfzelle verloren gehen
   - ✔ Weil sonst keine startfähige Firmware mehr auf dem Chip steht
   - Weil sonst das Betriebssystem neu aktiviert werden muss
   - Weil sonst die Garantie des Netzteils automatisch erlischt
   - Erklärung: Ein halb geschriebener Firmware-Chip kann das Mainboard unbrauchbar machen, sofern kein Dual-BIOS einspringt.

5. In welcher Reihenfolge prüfst du beim Bottom-up-Vorgehen?
   - Anwendung, Transport, Vermittlung, Sicherung, Bitübertragung
   - Vermittlung, Bitübertragung, Anwendung, Sicherung, Transport
   - ✔ Bitübertragung, Sicherung, Vermittlung, Transport, Anwendung
   - Sicherung, Bitübertragung, Transport, Vermittlung, Anwendung
   - Erklärung: Bottom-up beginnt bei Kabel und Link (Schicht 1) und geht Schicht für Schicht nach oben bis zum Dienst.

6. ping auf das Standardgateway klappt. Welche Schichten funktionieren damit im eigenen Netz nachweislich?
   - Nur Schicht 1, weil das Kabel steckt
   - ✔ Schicht 1 bis 3 im eigenen Netz
   - Schicht 1 bis 7, die ganze Verbindung
   - Nur Schicht 4, weil ein Port antwortet
   - Erklärung: Eine ICMP-Antwort braucht Leitung, Rahmenzustellung und IP-Adressierung. Über Ports und Dienste sagt sie nichts.

7. Der Intranetserver ist über seine IP-Adresse erreichbar, über seinen Namen nicht. Wo liegt der Fehler am wahrscheinlichsten?
   - Beim Netzwerkkabel des Rechners
   - ✔ Bei der Namensauflösung per DNS
   - Beim VLAN des Switchports
   - Beim Standardgateway des Rechners
   - Erklärung: Funktioniert die IP-Verbindung, sind die unteren Schichten in Ordnung. Fehlt nur der Name, ist es DNS.

8. ipconfig zeigt die Adresse 169.254.23.7. Was bedeutet das?
   - Der Rechner hat eine feste Adresse aus dem Firmennetz
   - Der Rechner ist per VPN mit der Zentrale verbunden
   - Der Rechner hat vom DHCP-Server eine Adresse erhalten
   - ✔ Der Rechner hat keinen DHCP-Server erreicht
   - Erklärung: 169.254.0.0/16 ist der APIPA-Bereich. Der Rechner hat sich die Adresse selbst gegeben, weil keine DHCP-Antwort kam.

9. Mit welchem Befehl prüfst du, ob TCP-Port 443 auf dem Webserver erreichbar ist?
   - Test-Connection webserver -Count 443 -Quiet
   - ✔ Test-NetConnection webserver -Port 443
   - tracert -h 443 webserver
   - nslookup webserver -port=443
   - Erklärung: Test-NetConnection mit -Port baut eine TCP-Verbindung auf. Test-Connection sendet nur ICMP-Echos wie ping, nslookup fragt nur den Namen ab.

10. Welches Werkzeug zeigt, an welchem Router auf dem Weg zum Ziel die Verbindung abbricht?
   - netstat -an
   - ipconfig /renew
   - ✔ tracert
   - arp -a
   - Erklärung: tracert listet die Router nacheinander auf. Endet die Liste, liegt der Fehler hinter dem letzten antwortenden Router.

### Karteikarten

- **Kein Bild, Debug-LED „CPU“, Prozessor neuer als das Mainboard?** → Wahrscheinlich kennt die Firmware den Prozessor nicht; CPU-Support-Liste prüfen und Firmware aktualisieren.
- **BIOS-Flashback — wozu?** → Firmware vom USB-Stick einspielen, ohne dass Prozessor, Arbeitsspeicher oder Grafik arbeiten müssen.
- **BIOS-Flashback — Voraussetzungen?** → Firmware für das exakte Modell, nach Vorgabe benannt, FAT32-Stick im markierten Anschluss, Netzteil mit 24-poligem und CPU-Stecker.
- **Risiko eines Firmware-Updates und Gegenmaßnahme?** → Stromausfall hinterlässt keine startfähige Firmware; Strom sichern, USV, richtige Datei, Prüfsumme, Dual-BIOS nutzen.
- **CMOS-Reset?** → Setzt die UEFI-Einstellungen auf Werkseinstellung zurück, per Jumper, Taste oder kurz entnommener Knopfzelle; ändert die Firmware nicht.
- **Bottom-up-Fehlersuche?** → Von Schicht 1 nach oben prüfen; die nächste Schicht erst, wenn die untere nachweislich funktioniert.
- **ping auf das Gateway klappt — was ist bewiesen?** → Schicht 1 bis 3 im eigenen Netz funktionieren: Kabel, Switch, IP-Adressierung.
- **Adresse aus 169.254.0.0/16?** → APIPA: Der Rechner hat keine DHCP-Antwort bekommen; Kabel, VLAN und DHCP-Server prüfen.
- **Über IP erreichbar, über Namen nicht?** → Fehler in der Namensauflösung: DNS-Server in ipconfig /all prüfen, mit nslookup testen.
- **Test-NetConnection -Port?** → PowerShell-Befehl, der prüft, ob ein TCP-Port am Ziel erreichbar ist, etwa 443 für HTTPS.

### Aufgaben

**Aufgabe 1** (5 Punkte, Freitext)

Der neue Konstruktionsrechner der Lahnwerk Metallbau GmbH zeigt kein Bild, die Lüfter drehen, die Debug-LED „CPU“ leuchtet. Prozessor und Mainboard wurden neu gekauft, der Prozessor gehört zur neuesten Generation. Erkläre die wahrscheinliche Ursache und nenne zwei andere Ursachen, die du vorher ausschließt.

Musterlösung: Wahrscheinliche Ursache: Die ausgelieferte Firmware des Mainboards ist älter als der Prozessor und unterstützt ihn noch nicht; der Start bricht vor der Bildausgabe ab. Bestätigt wird das über die CPU-Support-Liste des Herstellers, die nennt, ab welcher Firmware-Version der Prozessor läuft. Vorher ausschließen: fehlender oder lockerer 8-poliger CPU-Stromstecker, Prozessor nicht richtig eingesetzt oder verbogene Kontakte, Kühler zu fest oder schief montiert.

Stichwörter: Firmware, unterstützt, Support-Liste, CPU-Stromstecker

**Aufgabe 2** (6 Punkte, Freitext)

Das Mainboard des Konstruktionsrechners hat eine Flashback-Funktion. Beschreibe Schritt für Schritt, wie du die passende Firmware einspielst, obwohl der Rechner nicht startet, und nenne zwei Punkte, auf die du während und nach dem Vorgang achtest.

Musterlösung: Firmware für das exakte Mainboard-Modell von der Herstellerseite laden; Datei nach Herstellervorgabe umbenennen; auf einen FAT32-formatierten USB-Stick kopieren; Stick in den markierten Flashback-Anschluss stecken; Netzteil mit 24-poligem und CPU-Stecker anschließen; Flashback-Taste drücken, bis die LED blinkt; warten, bis die LED erlischt. Währenddessen: Strom nicht unterbrechen, nicht vorzeitig abschalten. Danach: normal starten, im UEFI die Standardeinstellungen laden, Einstellungen wie Speicherprofil und Startreihenfolge prüfen und das Update dokumentieren.

Stichwörter: exakte, FAT32, umbenennen, LED, Strom

**Aufgabe 3** (5 Punkte, Zuordnung)

Bei der Lahnwerk Metallbau GmbH sind diese Störungen aufgetreten. Ordne jeder Störung die OSI-Schicht zu, in der die Ursache liegt.

- Das Patchkabel am Switch wurde beim Umbau abgezogen, die Link-LED am Rechner ist aus. → Schicht 1 Bitübertragung
- Der Switchport des Rechners steckt im Gäste-VLAN, der Rechner bekommt eine Adresse aus dem Gästenetz. → Schicht 2 Sicherung
- Als Standardgateway ist eine falsche Adresse eingetragen; Rechner im eigenen Subnetz sind erreichbar, alles andere nicht. → Schicht 3 Vermittlung
- ping zum Webserver klappt, aber die Firewall verwirft Verbindungen auf TCP-Port 443. → Schicht 4 Transport
- Über die IP-Adresse öffnet sich die Seite, über den Namen meldet der Browser, die Adresse sei nicht zu finden. → Schicht 7 Anwendung

Musterlösung: Kabel abgezogen, Link-LED aus: Bitübertragung. Falsches VLAN am Switchport: Sicherung. Falsches Standardgateway: Vermittlung. Firewall sperrt Port 443: Transport. DNS kennt den Namen nicht: Anwendung.

Stichwörter: Bitübertragung, Sicherung, Vermittlung, Transport, Anwendung

**Aufgabe 4** (6 Punkte, Freitext)

Ein Büro-PC der Lahnwerk Metallbau GmbH kann die Intranetseite intranet.lahnwerk.local nicht öffnen. Deine Befunde: Die Link-LED leuchtet. ipconfig zeigt 192.168.20.57/24 mit Gateway 192.168.20.1. ping 192.168.20.1 wird beantwortet. ping 10.0.5.10, die Adresse des Intranetservers, wird beantwortet. nslookup intranet.lahnwerk.local meldet, der Name sei nicht vorhanden; als antwortender Server erscheint 8.8.8.8. Ordne die Befunde den OSI-Schichten zu, benenne die Ursache und den nächsten Schritt.

Musterlösung: Link-LED: Schicht 1 in Ordnung. Gültige Adresse und Antwort des Gateways: Schicht 2 und 3 im eigenen Netz in Ordnung. Antwort des Intranetservers per IP: Routing zum Server funktioniert. nslookup scheitert, und es antwortet ein öffentlicher DNS-Server, der die interne Zone nicht kennt: Fehler in der Namensauflösung, Schicht 7. Ursache: Am PC ist 8.8.8.8 statt des internen DNS-Servers eingetragen. Nächster Schritt: DNS-Eintrag mit ipconfig /all prüfen, auf den internen DNS-Server umstellen oder die DHCP-Option korrigieren, dann ipconfig /flushdns und mit nslookup erneut testen.

Stichwörter: DNS, 8.8.8.8, interne, nslookup, Schicht 7

**Aufgabe 5** (6 Punkte, Freitext)

Ein Mitarbeiter der Lahnwerk Metallbau GmbH meldet: „Kein Internet.“ ipconfig zeigt an seinem Rechner die Adresse 169.254.88.14 und kein Standardgateway. Die Kollegen am selben Switch arbeiten normal. Erkläre, was die Adresse bedeutet, und beschreibe in sinnvoller Reihenfolge drei Prüfschritte bis zur Ursache.

Musterlösung: 169.254.0.0/16 ist der APIPA-Bereich: Der Rechner hat keine Antwort von einem DHCP-Server bekommen und sich selbst eine Adresse gegeben. Weil die Kollegen arbeiten, läuft der DHCP-Server wahrscheinlich. Prüfschritte von unten: 1. Kabel und Link-LED an Rechner und Switchport, Dose richtig gepatcht. 2. Switchport aktiv und im richtigen VLAN, nicht etwa im Gäste- oder einem leeren VLAN. 3. Mit ipconfig /renew eine neue Adresse anfordern und das Ergebnis prüfen; bleibt es bei APIPA, Netzwerkkarte, Treiber und Port-Sicherheit am Switch prüfen.

Stichwörter: APIPA, DHCP, Link-LED, VLAN, ipconfig /renew

**Aufgabe 6** (4 Punkte, Freitext)

Deine Kollegin sagt: „ping auf den Webserver geht nicht, also ist der Server aus.“ Die Seite des Webservers lädt im Browser aber bei anderen Kollegen. Erkläre, warum ihr Schluss falsch sein kann, und wie du die Erreichbarkeit des Dienstes richtig prüfst.

Musterlösung: ping nutzt ICMP. Viele Firewalls verwerfen ICMP, obwohl der Dienst erreichbar ist; ein fehlendes Echo beweist also nicht, dass der Server aus ist. Richtig prüft man den Dienstport: Test-NetConnection webserver -Port 443 zeigt, ob die TCP-Verbindung auf HTTPS zustande kommt. Ergänzend nslookup für die Namensauflösung und tracert, um zu sehen, wie weit die Pakete kommen. Das Ergebnis jedes Schritts wird im Ticket notiert.

Stichwörter: ICMP, Firewall, Test-NetConnection, 443

### Lückentexte

- Die Mainboard-Funktion, die eine Firmware vom USB-Stick einspielt, ohne dass Prozessor und Arbeitsspeicher arbeiten müssen, heißt allgemein BIOS-[[1]].  → Antworten: Flashback / Flash-Back / Flash Back
- Erhält ein Windows-Rechner keine Antwort vom DHCP-Server, gibt er sich eine Adresse aus 169.254.0.0/16. Dieses Verfahren heißt [[1]].  → Antworten: APIPA / Apipa
- Wer bei der Fehlersuche mit Kabel und Link-LED beginnt und sich Schicht für Schicht nach oben arbeitet, geht nach dem Verfahren [[1]] vor.  → Antworten: Bottom-up / Bottom up / bottom-up / Bottom-Up
- Um zu prüfen, welche IP-Adresse ein DNS-Server zu einem Namen liefert und welcher Server geantwortet hat, nutzt man unter Windows den Befehl [[1]].  → Antworten: nslookup / Resolve-DnsName

### Reihenfolge (hier in richtiger Reihenfolge; im Portal gemischt)

Ein Rechner der Lahnwerk Metallbau GmbH erreicht den Dateiserver nicht. Du gehst nach dem Bottom-up-Verfahren vor. Bring die Prüfschritte in die richtige Reihenfolge.

1. Kabel, Dose und Link-LED an Rechner und Switch prüfen
2. Switchport und VLAN in der Verwaltung des Switches prüfen
3. Mit ipconfig /all Adresse, Maske, Gateway und DNS-Server prüfen
4. Standardgateway und Dateiserver mit ping testen
5. Mit Test-NetConnection den Port des Dateidienstes prüfen
6. Mit nslookup den Namen des Dateiservers auflösen

Erklärung: Jede Schicht baut auf der darunter auf: Leitung, Switch und VLAN, IP-Konfiguration, Erreichbarkeit, Port, Name. Wer oben anfängt, sucht bei einem abgezogenen Kabel lange an der falschen Stelle.


---

