��            )   �      �  &   �  4   �    �  .        @  a  _  .   �	  +   �	  :   
  I   W
  "   �
  C   �
  %        .  '   N  )   v  0   �  ;   �  O     /   ]  +   �  &   �  1   �  -     0   @  4   q  ;   �  %   �       �  '  *   �  7   �  F    +   R  "   ~  �  �  <   `  )   �  F   �  O     )   ^  K   �  )   �      �  %     ,   E  ,   r  ;   �  3   �  *     ,   :  ,   g  D   �  9   �  1     3   E  <   y  +   �     �                                       	                                                              
                                              output file remains in '%s'
           which is the target of symbolic link '%s'
  -F, --follow-symlink  follow symbolic links and convert the targets
 -R, --replace-symlink replace symbolic links with converted files
                       (original target files remain unchanged)
 -S, --skip-symlink    keep symbolic links and targets unchanged (default)
  -V, --version         display version number
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
POT-Creation-Date: 2011-04-13 08:43+0200
PO-Revision-Date: 2010-03-07 19:50+0100
Last-Translator: Ruĝulo <ruĝulo@gmail.com>
Language-Team: Esperanto <translation-team-eo@lists.sourceforge.net>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
Plural-Forms: nplurals=2; plural=(n != 1);
           kreatan dosieron restas en '%s'
           kiu estas la atingon de dosiera ĉenero '%s'
  -F, --follow-symlink  legu dosierajn ĉenerojn kaj konverti la atingojn
 -R, --replace-symlink anstataŭe registru dosierajn ĉenerojn per konvertotaj dosieroj
                       (ne-ĉeneraj atingaj dosieroj restas neŝanĝitaj)
 -S, --skip-symlink    retenu dosierajn ĉenerojn kaj atingojn neŝanĝataj (jam ŝaltita)
  -V, --version         diri eldono-numeron
 Uzante denaskan lingvon sistemon.
 dos2unix %s (%s)
Uzado: dos2unix [elektojn] [dosiero ...] [-n antaŭaĵo kreaĵo ...]
 -ascii                nur traduku linio-finojn (jam enŝaltita)
 -iso                  traduku inter DOS kaj ISO-8859-1 literaro
   -1252               Uzu Vindozan kodpaĝon 1252 (Okcident-Eŭropa)
   -437                Uzu DOS kodpaĝon 437 (Usona) (jam enŝaltita)
   -850                Uzu DOS kodpaĝon 850 (Okcident-Eŭropa)
   -860                Uzu DOS kodpaĝon 860 (Portugala)
   -863                Uzu DOS kodpaĝon 863 (Kebekia)
   -865                Uzu DOS kodpaĝon 865 (Nordlandaj)
 -7                    Traduku de 8-bitaj literoj en blankspacon
 -c, --convmode        modo de ŝanĝo
   ŝanĝmodo            ascii, 7bit, iso, mac, provizore elektita ascii
 -f, --force           forte konvertado de netekstaj dosieroj
 -h, --help            diri ĉi tiun mesaĝon
 -k, --keepdate        konservi dato-tempon dosieran
 -L, --license         eldiru permesilon tekstan
 -l, --newline         aldoni markon linian finan
 -n, --newfile         registri novan dosieron
   antaŭaĵo            al antaŭa dosiero metita novmoden
   kreaĵo              al dosiero registrita novmoden
 -o, --oldfile         registri malnovan dosieron
   dosiero...          dosiero(j)n por registri per malnova modo
 -q, --quiet           silente eviti avertojn
                       ĉiam enŝaltata dum stdio modo
 -s, --safe            evitu netekstajn dosierojn (jam ŝaltita)
 dos2unix: malsukcesis malfermi provizoran dosieron registran dos2unix: Pasante %s, dosiero ne tauĝa.
 dos2unix: Evitante %s, atingan dosieron %s jam estas dosiera ĉenero.
 dos2unix: Evitante %s, atingon de dosiera ĉenero %s ne estas normala dosiero.
 dos2unix: Pasante ne-tekstan dosieron %s
 dos2unix: Evitante dosieran ĉeneron %s, atingon ne estas normala dosiero.
 dos2unix: Evitante dosieran ĉeneron %s.
 dos2unix: nuntempa kodpaĝo: %d
 dos2unix: ne povas registri dosieren
 dos2unix: kodpaĝo %d ne estas konvertebla.
 dos2unix: ŝanĝante dosiero %s Unix-en ...
 dos2unix: ŝanĝante dosieron %s al dosiero %s Unix-en ...
 dos2unix: eraro: DOS2UNIX_LOCALEDIR tro longiĝis.
 dos2unix: neuzebla %s ŝanĝmodo menciita
 dos2unix: elekto '%s' bezonas elekto-vorton
 dos2unix: problemojn dum ŝanĝi dosiero %s
 dos2unix: problemojn trovitajn dum ŝanĝi dosiero %s al dosiero %s
 dos2unix: problemojn trovitajn renomigi '%s' al '%s': %s
 dos2unix: erarojn legante dosieran ĉeneron '%s'
 dos2unix: programa eraro, neĝustan ŝanĝmodon %d
 dos2unix: ejon de dosiero %s ne menciita en novmodo dosiera
 dos2unix: uzante %s kiel provizora dosiero
 dos2unix: uzante kodpaĝon %d.
 