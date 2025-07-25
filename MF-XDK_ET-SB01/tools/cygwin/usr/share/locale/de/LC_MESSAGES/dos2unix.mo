��            )         �  &   �  4   �      .   !  J  P     �	  a  �	  .     +   K  :   w  I   �  "   �  C     %   c     �  '   �  )   �  0   �  ;   ,  O   h  /   �  +   �  &     1   ;  -   m  0   �  4   �  ;     %   =     c  �  �  /     C   O  f  �  3   �  x  .  '   �  4  �  C   $  A   H$  T   �$  f   �$  .   F%  `   u%  :   �%     &  <   0&  /   m&  8   �&  C   �&  T   '  @   o'  3   �'  @   �'  O   %(  M   u(  N   �(  E   )  N   X)  1   �)  &   �)                                       
         	                                                                                                  output file remains in '%s'
           which is the target of symbolic link '%s'
  -F, --follow-symlink  follow symbolic links and convert the targets
 -R, --replace-symlink replace symbolic links with converted files
                       (original target files remain unchanged)
 -S, --skip-symlink    keep symbolic links and targets unchanged (default)
  -V, --version         display version number
 Copyright (C) 2009-2011 Erwin Waterlander
Copyright (C) 1998      Christian Wurll (Version 3.1)
Copyright (C) 1998      Bernd Johannes Wuebben (Version 3.0)
Copyright (C) 1994-1995 Benjamin Lin
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice in the documentation and/or other materials provided with
   the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 With native language support.
 dos2unix %s (%s)
Usage: dos2unix [options] [file ...] [-n infile outfile ...]
 -ascii                convert only line breaks (default)
 -iso                  conversion between DOS and ISO-8859-1 character set
   -1252               Use Windows code page 1252 (Western European)
   -437                Use DOS code page 437 (US) (default)
   -850                Use DOS code page 850 (Western European)
   -860                Use DOS code page 860 (Portuguese)
   -863                Use DOS code page 863 (French Canadian)
   -865                Use DOS code page 865 (Nordic)
 -7                    Convert 8 bit characters to 7 bit space
 -c, --convmode        conversion mode
   convmode            ascii, 7bit, iso, mac, default to ascii
 -f, --force           force conversion of binary files
 -h, --help            give this help
 -k, --keepdate        keep output file date
 -L, --license         display software license
 -l, --newline         add additional newline
 -n, --newfile         write to new file
   infile              original file in new file mode
   outfile             output file in new file mode
 -o, --oldfile         write to old file
   file ...            files to convert in old file mode
 -q, --quiet           quiet mode, suppress all warnings
                       always on in stdio mode
 -s, --safe            skip binary files (default)
 dos2unix: Failed to open temporary output file dos2unix: Skipping %s, not a regular file.
 dos2unix: Skipping %s, output file %s is a symbolic link.
 dos2unix: Skipping %s, target of symbolic link %s is not a regular file.
 dos2unix: Skipping binary file %s
 dos2unix: Skipping symbolic link %s, target is not a regular file.
 dos2unix: Skipping symbolic link %s.
 dos2unix: active code page: %d
 dos2unix: can not write to output file
 dos2unix: code page %d is not supported.
 dos2unix: converting file %s to Unix format ...
 dos2unix: converting file %s to file %s in Unix format ...
 dos2unix: error: Value of environment variable DOS2UNIX_LOCALEDIR is too long.
 dos2unix: invalid %s conversion mode specified
 dos2unix: option '%s' requires an argument
 dos2unix: problems converting file %s
 dos2unix: problems converting file %s to file %s
 dos2unix: problems renaming '%s' to '%s': %s
 dos2unix: problems resolving symbolic link '%s'
 dos2unix: program error, invalid conversion mode %d
 dos2unix: target of file %s not specified in new file mode
 dos2unix: using %s as temporary file
 dos2unix: using code page %d.
 Project-Id-Version: dos2unix 5.2
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2011-04-23 08:31+0200
PO-Revision-Date: 2010-01-24 09:00+0100
Last-Translator: Philipp Thomas <psmt@opensuse.org>
Language-Team: German <translation-team-de@lists.sourceforge.net>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Generator: Lokalize 1.0
Plural-Forms: nplurals=2; plural=n != 1;
           Die Ausgabedatei verbleibt in »%s«
           welche das Ziel der symbolischen Verknüpfung »%s« ist
  -F, --follow-symlink  folgt symbolischen Verknüpfungen und wandelt die Ziele um
 -R, --replace-symlink ersetzt symbolische Verknüpfungen durch die umgewandelten
                       Dateien (die Originale Ziele bleiben unangetastet)
 -S, --skip-symlink    symbolische Verknüpfungen und deren Ziele bleiben
                       unangetastet (Vorgabe)
  -V, --version         gibt die Versionsnummer aus
 Copyright © 2009-2011 Erwin Waterlander
Copyright © 1998      Christian Wurll (Version 3.1)
Copyright © 1998      Bernd Johannes Wuebben (Version 3.0)
Copyright © 1994,1995 Benjamin Lin
Alle Rechte vorbehalten.

Verbreitung und Verwendung als Quelltext oder Binärdatei, in geänderter
oder ungeänderter Form sind gestattet, soweit die folgenden Bedingungen
eingehalten werden:
1. Weiterverbreitung des Quellcodes muss den obigen Copyrightshinweis,
   Diese Liste von Bedingungen sowie den folgenden Haftungsausschlus
   beibehalten.
2. Weiterverbreitung in binärer Form muss den obigen Copyright-Hinweis
   in der Dokumentation oder anderem der Distribution beiliegenden
   Material wiedergeben.

DIESE SOFTWARE WIRD VOM AUTHOR WIE VORLIEGT ZUR VERFÜGUNG GESTELLT
UND JEGLICHE AUSDRÜCKLICH GENANNTEN ODER IMPLIZITEN GARANTIEN,
EINSCHLIESLICH, ABER NICHT DARAUF BESCHRÄNKT, DER GARANTIE DER
HANDELBARKEIT UND DER EIGNUNG FÜR EINEN BESTIMMTEN ZWECK WERDEN
HIERMIT AUSGESCHLOSSEN. IN KEINEM WIE AUCH IMMER GELAGERTEN FALL KANN
DER AUTHOR FÜR IRGENDWELCHE DIREKTEN ODER INDIREKTEN, ZUFÄLLIGEN,
BESONDEREN ODER BEISPIELHAFTEN SCHÄDEN (EINSCHLIESSLICH ABER NICHT
AUSSCHLIESSLICH DER LIEFERUNG VON ERSATZGÜTERN ODER DIENSTEN;VERLUST
DER NUTZBARKEIT, DER DATEN ODER DER GEWINNE ODER ETWAIGEN VERDIENST-
AUSFALL-ENTSCHÄDIGUNGEN) HAFTBAR GEMACHT WERDEN, WIE AUCH IMMER SIE
VERURSACHT WURDEN UND WELCHE HAFTUNGSMÖGLICHKEIT ZUGRUNDE GELEGT WIRD,
SEI ES DURCH VERTRAG, VERBINDLICHKEIT ODER SCHADEN (EINSCHLIESSLICH
FAHRLÄSSIGKEIT), DIE AUS DER VERWENDUNG DIESER SOFTWARE ERWÄCHST,
SELBST WENN AUF DIE MÖGLICHKIET SOLCHER SCHÄDEN HINGEWIESEN WURDE.
 Mit Unterstützung von Landessprachen.
 dos2unix %s (%s)
Aufruf: dos2unix [Optionen] [Datei ...] [-n Eingabedatei Ausgabedatei ...]
 -ascii                nur Zeilenumbrüche konvertieren (Vorgabe)
 -iso                  Konvertierung zwischen DOS und ISO-8859-1 Zeichensatz
   -1252               Windows Codepage 1252 verwenden (Westeuropäisch)
   -437                DOS Codepage 437 verwenden (US) (Vorgabe)
   -850                DOS Codepage 850 verwenden (Westeuropäisch)
   -860                DOS Codepage 860 verwenden (Portugiesisch)
   -863                DOS Codepage 863 verwenden (Kanadisches Französisch)
   -865                DOS Codepage 865 verwenden (Nordisch)
 -7                    8Bit Zeichen in solche aus dem 7Bit Raum konvertieren
 -c, --convmode        Konvertierungsmodus angeben
   convmode            ascii, 7bit, iso, mac, Standard ist nach ascii
 -f, --force           erzwingt die Umwandlung binärer Dateien
 -h, --help            gibt diese Hilfe
 -k, --keepdate        Datum der Ausgabedatei bleibt erhalten
 -L, --license         Ausgabe der Software-Lizenz
 -l, --newline         fügt einen Zeilenumbruch hinzu
 -n, --newfile         eine neue Datei wird erzeugt
   Eingabedatei        Originaldatei im neue Datei Modus
   Ausgabedatei        Ausgabedatei im neue Datei Modus
 -o, --oldfile         überschreibt die alte Datei
   Datei ...           Die im alte Datei Modus zu konvertierenden Dateien
 -q, --quiet           ruhiger Modus, unterdrückt alle Warnungen
                       ist im stdio Modus immer aktiv
 -s, --safe            überspringt binäre Dateien (Vorgabe)
 dos2unix: Die temporäre Ausgabedatei konnte nicht geöffnet werden dos2unix: %s wird übersprungen, da es keine reguläre Datei ist
 dos2unix: %s wird übersprungen, Ausgabedatei %s ist eine symbolische Verknüpfung.
 dos2unix: %s wird übersprungen, das Ziel der symbolischen Verknüpfung %s ist keine reguläre Datei.
 dos2unix: binäre Datei %s wird übersprungen
 dos2unix: Symbolische Verknüpfung %s wird übersprungen da das Ziel keine reguläre Datei ist.
 dos2unix: Symbolische Verknüpfung %s wird übersprungen.
 dos2unix: aktive Codepage: %d
 dos2unix: In die Ausgabedatei kann nicht geschrieben werden
 dos2unix: Codepage %d wird nicht unterstützt.
 dos2unix: Datei %s wird ins Unix-Format umgewandelt ...
 dos2unix: Datei %s wird zu Datei %s im Unix-Format umgewandelt ...
 dos2unix: Fehler: Der Inhalt der Umgebungsvariablen DOS2UNIX_LOCALEDIR ist zu lang.
 dos2unix: Der angegebene Konvertierungsmodus %s ist unzulässig
 dos2unix: Die Option »%s« benötigt ein Argument
 dos2unix: Beim Umwandeln von Datei %s sind Probleme aufgetreten
 dos2unix: Beim Konvertieren von Datei %s zu Datei %s sind Probleme aufgetreten
 dos2unix: Beim Umbenennen von »%s« zu »%s« sind Probleme aufgetreten: %s
 dos2unix: es gab Probleme beim Auflösen der symbolischen Verknüpfung »%s«
 dos2unix: Programmfehler, der Konvertierungsmodus %d ist unzulässig
 dos2unix: Das Ziel der Datei %s wurde für den Neudatei-Modus nicht angegeben
 dos2unix: %s wird als temporäre Datei verwendet
 dos2unix: Codepage %d wird verwendet.
 