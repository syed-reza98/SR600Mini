��             +         �  &   �  4   �    %  .   9     h  a  �  .   �	  +   
  :   D
  I   
  "   �
  C   �
  %   0     V  '   v  )   �  /   �  /   �  :   (  :   c  O   �  /   �  +     &   J  1   q  -   �  0   �  4     ;   7  %   s     �  �  �  *   9  7   d  F  �  +   �  !     �  1  <   �  )   -  F   W  O   �  )   �  K     )   d      �  %   �  ,   �  +     +   .  9   Z  9   �  3   �  *     ,   -  $   Z  D     9   �  1   �  3   0  <   d  +   �     �                                                                                   	                                                     
                  output file remains in '%s'
           which is the target of symbolic link '%s'
  -F, --follow-symlink  follow symbolic links and convert the targets
 -R, --replace-symlink replace symbolic links with converted files
                       (original target files remain unchanged)
 -S, --skip-symlink    keep symbolic links and targets unchanged (default)
  -V, --version         display version number
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
 Project-Id-Version: unix2dos 5.2
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2011-04-13 08:43+0200
PO-Revision-Date: 2010-03-07 19:52+0100
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
 Uzante denaskan lingvo-sistemon.
 unix2dos %s (%s)
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
 unix2dos: malsukcesis malfermi provizoran dosieron registran unix2dos: Pasante %s, dosiero ne tauĝa.
 unix2dos: Evitante %s, atingan dosieron %s jam estas dosiera ĉenero.
 unix2dos: Evitante %s, atingon de dosiera ĉenero %s ne estas normala dosiero.
 unix2dos: Pasante ne-tekstan dosieron %s
 unix2dos: Evitante dosieran ĉeneron %s, atingon ne estas normala dosiero.
 unix2dos: Evitante dosieran ĉeneron %s.
 unix2dos: nuntempa kodpaĝo: %d
 unix2dos: ne povas registri dosieren
 unix2dos: kodpaĝo %d ne estas konvertebla.
 unix2dos: ŝanĝante dosiero %s DOS-en ...
 unix2dos: ŝanĝante dosiero %s Mac-en ...
 unix2dos: ŝanĝante dosiero %s al dosiero %s DOS-en ...
 unix2dos: ŝanĝante dosiero %s al dosiero %s Mac-en ...
 unix2dos: eraro: DOS2UNIX_LOCALEDIR tro longiĝis.
 unix2dos: neuzebla %s ŝanĝmodo menciita
 unix2dos: elekto '%s' bezonas elekto-vorton
 unix2dos: problemojn dum ŝanĝi %s
 unix2dos: problemojn trovitajn dum ŝanĝi dosiero %s al dosiero %s
 unix2dos: problemojn trovitajn renomigi '%s' al '%s': %s
 unix2dos: erarojn legante dosieran ĉeneron '%s'
 unix2dos: programa eraro, neĝustan ŝanĝmodon %d
 unix2dos: ejon de dosiero %s ne menciita en novmodo dosiera
 unix2dos: uzante %s kiel provizora dosiero
 unix2dos: uzante kodpaĝon %d.
 