��    !      $  /   ,      �  &   �  4       E  .   Y  �  �     `	  a  	  .   �  +     :   <  I   w  "   �  C   �  %   (     N  '   n  )   �  /   �  /   �  :      :   [  O   �  /   �  +     &   B  1   i  -   �  0   �  4   �  ;   /  %   k     �  �  �  +   G  C   s  f  �  3     
  R  &   ]  4  �  C   �#  A   �#  T   ?$  f   �$  2   �$  `   .%  :   �%     �%  3   �%  /   &  7   M&  7   �&  B   �&  B    '  T   C'  >   �'  3   �'  C   (  S   O(  D   �(  N   �(  =   7)  J   u)  1   �)  &   �)                                                                                                      
                 	                         !                         output file remains in '%s'
           which is the target of symbolic link '%s'
  -F, --follow-symlink  follow symbolic links and convert the targets
 -R, --replace-symlink replace symbolic links with converted files
                       (original target files remain unchanged)
 -S, --skip-symlink    keep symbolic links and targets unchanged (default)
  -V, --version         display version number
 Copyright (C) 2009-2011 Erwin Waterlander
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
 unix2dos %s (%s)
Usage: unix2dos [options] [file ...] [-n infile outfile ...]
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
 unix2dos: Failed to open temporary output file unix2dos: Skipping %s, not a regular file.
 unix2dos: Skipping %s, output file %s is a symbolic link.
 unix2dos: Skipping %s, target of symbolic link %s is not a regular file.
 unix2dos: Skipping binary file %s
 unix2dos: Skipping symbolic link %s, target is not a regular file.
 unix2dos: Skipping symbolic link %s.
 unix2dos: active code page: %d
 unix2dos: can not write to output file
 unix2dos: code page %d is not supported.
 unix2dos: converting file %s to DOS format ...
 unix2dos: converting file %s to Mac format ...
 unix2dos: converting file %s to file %s in DOS format ...
 unix2dos: converting file %s to file %s in Mac format ...
 unix2dos: error: Value of environment variable DOS2UNIX_LOCALEDIR is too long.
 unix2dos: invalid %s conversion mode specified
 unix2dos: option '%s' requires an argument
 unix2dos: problems converting file %s
 unix2dos: problems converting file %s to file %s
 unix2dos: problems renaming '%s' to '%s': %s
 unix2dos: problems resolving symbolic link '%s'
 unix2dos: program error, invalid conversion mode %d
 unix2dos: target of file %s not specified in new file mode
 unix2dos: using %s as temporary file
 unix2dos: using code page %d.
 Project-Id-Version: dos2unix 5.2
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2011-04-13 08:43+0200
PO-Revision-Date: 2010-02-05 16:34+0100
Last-Translator: Philipp Thomas <pth@suse.de>
Language-Team: German <translation-team-de@lists.sourceforge.net>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Generator: Lokalize 1.0
Plural-Forms: nplurals=2; plural=n != 1;
           Ausgabedatei verbleibt in »%s«
           welche das Ziel der symbolischen Verknüpfung »%s« ist
  -F, --follow-symlink  folgt symbolischen Verknüpfungen und wandelt die Ziele um
 -R, --replace-symlink ersetzt symbolische Verknüpfungen durch die umgewandelten
                       Dateien (die Originale Ziele bleiben unangetastet)
 -S, --skip-symlink    symbolische Verknüpfungen und deren Ziele bleiben
                       unangetastet (Vorgabe)
  -V, --version         gibt die Versionsnummer aus
 Copyright © 2009,2011 Erwin Waterlander
Copyright © 1994,1995 Benjamin Lin
Alle Rechte vorbehalten.

Verbreitung und Verwendung als Quelltext oder Binärdatei, in geänderter
oder ungeänderter Form sind gestattet, soweit die folgenden Bedingungen
eingehalten werden:
1. Weiterverbreitung des Quellcodes muss den obigen Copyrightshinweis,
   Diese Liste von Bedingungen sowie den folgenden Haftungsausschluss

   beibehalten.
2. Weiterverbreitung in binärer Form muss den obigen Copyright-Hinweis
   in der Dokumentation oder anderem der Distribution beiliegenden
   Material wiedergeben.

DIESE SOFTWARE WIRD VOM AUTHOR WIE VORLIEGT ZUR VERFÜGUNG GESTELLT
UND JEGLICHE AUSDRÜCKLICH GENANNTEN ODER IMPLIZITEN GARANTIEN,
EINSCHLIEßLICH, ABER NICHT DARAUF BESCHRÄNKT, DER GARANTIE DER
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
 Mit Unterstützung von Landessprachen
 unix2dos %s (%s)
Aufruf: unix2dos [Optionen] [Datei ...] [-n Eingabedatei Ausgabedatei ...]
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
 unix2dos: Die temporäre Ausgabedatei konnte nicht geöffnet werden unix2dos: %s wird übersprungen da es keine reguläre Datei ist.
 unix2dos: %s wird übersprungen, Ausgabedatei %s ist eine symbolische Verknüpfung.
 unix2dos: %s wird übersprungen, das Ziel der symbolischen Verknüpfung %s ist keine reguläre Datei.
 unix2dos: die binäre Datei %s wird übersprungen
 unix2dos: Symbolische Verknüpfung %s wird übersprungen da das Ziel keine reguläre Datei ist.
 unix2dos: Symbolische Verknüpfung %s wird übersprungen.
 unix2dos: aktive Codepage: %d
 unix2dos: Schreiben in Ausgabedatei nicht möglich
 unix2dos: Codepage %d wird nicht unterstützt.
 unix2dos: Datei %s wird ins DOS-Format konvertiert ...
 unix2dos: Datei %s wird ins Mac-Format konvertiert ...
 unix2dos: Datei %s wird in Datei %s im DOS-Format konvertiert ...
 unix2dos: Datei %s wird in Datei %s im Mac-Format konvertiert ...
 unix2dos: Fehler: Der Inhalt der Umgebungsvariablen DOS2UNIX_LOCALEDIR ist zu lang.
 unix2dos: der angegebene Konvertierungsmodus %s ist ungültig
 unix2dos: Die Option »%s« benötigt ein Argument
 unix2dos: beim Konvertieren von Datei %s sind Probleme aufgetreten
 unix2dos: bei der Konvertierung von Datei %s in Datei %s sind Probleme aufgetreten
 unix2dos: es gibt Probleme beim Umbenennen von »%s« zu »%s«: %s
 unix2dos: es gab Probleme beim Auflösen der symbolischen Verknüpfung »%s«
 unix2dos: Programmfehler: ungültiger Konvertierungsmodus %d
 unix2dos: das Ziel von Datei %s wurde im neue Datei Modus nicht angegeben
 unix2dos: %s wird als temporäre Datei verwendet
 unix2dos: Codepage %d wird verwendet.
 