# dbg-main.inc - Bourne Again Shell Debugger Main Include

#   Copyright (C) 2002, 2003, 2004, 2005, 2006 Rocky Bernstein 
#   rockyb@users.sourceforge.net
#
#   Bash is free software; you can redistribute it and/or modify it under
#   the terms of the GNU General Public License as published by the Free
#   Software Foundation; either version 2, or (at your option) any later
#   version.
#
#   Bash is distributed in the hope that it will be useful, but WITHOUT ANY
#   WARRANTY; without even the implied warranty of MERCHANTABILITY or
#   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
#   for more details.
#   
#   You should have received a copy of the GNU General Public License along
#   with Bash; see the file COPYING.  If not, write to the Free Software
#   Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA.

typeset -r _Dbg_main_ver=\
'$Id: dbg-main.inc.in,v 1.5 2007/10/14 03:53:24 rockyb Exp $'

# Are we using a debugger-enabled bash? If not let's stop right here.
if [[ -z "${BASH_SOURCE[0]}" ]] ; then 
  echo "Sorry, you need to use a debugger-enabled version of bash." 2>&1
  exit 2
fi

# $_Dbg_libdir could have been set by bashdb script.
# If not, set if "bash --debugger"
prefix=/usr  # cygwin gets PKGDATADIR wrong
[ -z $_Dbg_libdir ] && typeset _Dbg_libdir=/usr/share/bashdb

# Note: "init" comes first and "cmds" has to come after "io". Otherwise 
# these are sorted alphabetically.
typeset -r _Dbg_includes="init brk complete file fns help hist info log io 
cmds commands list stack set show sig"

for file in $_Dbg_includes ; do 
  source ${_Dbg_libdir}/dbg-${file}.inc
done

if [[ ${_Dbg_libdir:0:1} == '.' ]] ; then
    # Relative file name
    _Dbg_libdir=$(_Dbg_expand_filename ${_Dbg_init_cwd}/${_Dbg_libdir})
fi

[ -n "$BASHDB_RESTART_FILE" ] \
   && [ -r "$BASHDB_RESTART_FILE" ] &&  source $BASHDB_RESTART_FILE

trap '_Dbg_debug_trap_handler 0 "$BASH_COMMAND" "$@"' DEBUG
# echo '*** we were here***'  # uncomment to test that we were run.

#;;; Local Variables: ***
#;;; mode:shell-script ***
#;;; eval: (sh-set-shell "bash") ***
#;;; End: ***
