# dbg-set.inc - Bourne Again Shell Debugger Set Routines
#
#   Copyright (C) 2002,2003,2006,2007 Rocky Bernstein 
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

# Sets whether or not to display command to be executed in debugger prompt.
# If yes, always show. If auto, show only if the same line is to be run
# but the command is different.

# Set initial line tracing flag off
typeset -i _Dbg_linetrace=0 
typeset -i _Dbg_linetrace_expand=0 # expand variables in linetrace output
typeset -i _Dbg_linetrace_delay=0  # sleep after linetrace

_Dbg_do_set() {
  local set_cmd=$1
  if [[ $set_cmd == '' ]] ; then
    _Dbg_msg "Argument required (expression to compute)."
    return;
  fi
  shift
  case $set_cmd in 
    ar | arg | args )
      # We use the loop below rather than _Dbg_set_args="(@)" because
      # we want to preserve embedded blanks in the arguments.
      _Dbg_script_args=()
      local -i i
      local -i n=$#
      for (( i=0; i<n ; i++ )) ; do
	_Dbg_write_journal_eval "_Dbg_script_args[$i]=$1"
	shift
      done
      ;;
    an | ann | anno | annot | annota | annotat | annotate )
      eval "$_seteglob"
      if [[ $1 == $int_pat ]] ; then 
	if (( $1 > 1 )) ; then
	  _Dbg_msg "annotation level must be 0 or 1"
	else
	_Dbg_write_journal_eval "_Dbg_annotate=$1"
	fi
      else
	eval "$_resteglob"
	_Dbg_msg "Integer argument expected; got: $1"
	return 1
      fi
      eval "$_resteglob"
      return 0
      ;;
    b | ba | bas | base | basen | basena | basenam | basename )
      local onoff=${1:-'off'}
      case $onoff in 
	on | 1 ) 
	  _Dbg_write_journal_eval "_Dbg_basename_only=1"
	  ;;
	off | 0 )
	  _Dbg_write_journal_eval "_Dbg_basename_only=0"
	  ;;
	* )
	  _Dbg_msg "\"on\" or \"off\" expected."
	  return 1
      esac
      return 0
      ;;
    e | ed | edi | edit | editi | editin | editing )
      local onoff=${1:-'on'}
      case $onoff in 
	on | 1 ) 
	  _Dbg_edit='-e'
	  ;;
	off | 0 )
	  _Dbg_edit=''
	  ;;
	* )
	  _Dbg_msg "\"on\" or \"off\" expected."
      esac
      ;;
    d|de|deb|debu|debug|debugg|debugger|debuggi|debuggin|debugging )
      local onoff=${1:-'on'}
      case $onoff in 
	on | 1 ) 
	  _Dbg_write_journal_eval "_Dbg_debug_debugger=1"
	  ;;
	off | 0 )
	  _Dbg_write_journal_eval "_Dbg_debug_debugger=0"
	  ;;
	* )
	  _Dbg_msg "\"on\" or \"off\" expected."
      esac
      ;;
    li | lis | list | lists | listsi | listsiz | listsize )
      eval "$_seteglob"
      if [[ $1 == $int_pat ]] ; then 
	_Dbg_write_journal_eval "_Dbg_listsize=$1"
      else
	eval "$_resteglob"
	_Dbg_msg "Integer argument expected; got: $1"
	return 1
      fi
      eval "$_resteglob"
      return 0
      ;;
    lin | line | linet | linetr | linetra | linetrac | linetrace )
      local onoff=${1:-'off'}
      case $onoff in 
	on | 1 ) 
	  _Dbg_write_journal_eval "_Dbg_linetrace=1"
	  ;;
	off | 0 )
	  _Dbg_write_journal_eval "_Dbg_linetrace=0"
	  ;;
	d | de | del | dela | delay )
	  eval "$_seteglob"
	  if [[ $2 != $int_pat ]] ; then 
	    _Dbg_msg "Bad int parameter: $2"
	    eval "$_resteglob"
	    return 1
	  fi
	  eval "$_resteglob"
	  _Dbg_write_journal_eval "_Dbg_linetrace_delay=$2"
          ;;
	e | ex | exp | expa | expan | expand )
	  local onoff=${2:-'on'}
	  case $onoff in 
	    on | 1 ) 
	      _Dbg_write_journal_eval "_Dbg_linetrace_expand=1"
	      ;;
	    off | 0 )
	      _Dbg_write_journal_eval "_Dbg_linetrace_expand=0"
	      ;;
	    * )
	      _Dbg_msg "\"expand\", \"on\" or \"off\" expected."
             ;;
	  esac
	  ;;
	
	* )
	  _Dbg_msg "\"expand\", \"on\" or \"off\" expected."
	  return 1
      esac
      return 0
      ;;
    lo | log | logg | loggi | loggin | logging )
      _Dbg_cmd_set_logging $*
      ;;
    p | pr | pro | prom | promp | prompt )
      _Dbg_prompt_str="$1"
      ;;
    sho|show|showc|showco|showcom|showcomm|showcomma|showcomman|showcommand )
      case $1 in 
	1 )
	  _Dbg_write_journal_eval "_Dbg_show_command=on"
	  ;;
	0 )
	  _Dbg_write_journal_eval "_Dbg_show_command=off"
	  ;;
	on | off | auto )
	  _Dbg_write_journal_eval "_Dbg_show_command=$1"
	  ;;
	* )
	  _Dbg_msg "\"on\", \"off\" or \"auto\" expected."
      esac
      return 0
      ;;
    t|tr|tra|trac|trace|trace-|trace-c|trace-co|trace-com|trace-comm|trace-comma|trace-comman|trace-command|trace-commands )
      case $1 in 
	1 )
	  _Dbg_write_journal_eval "_Dbg_trace_commands=on"
	  ;;
	0 )
	  _Dbg_write_journal_eval "_Dbg_trace_commands=off"
	  ;;
	on | off )
	  _Dbg_write_journal_eval "_Dbg_trace_commands=$1"
	  ;;
	* )
	  _Dbg_msg "\"on\", \"off\" expected."
      esac
      return 0
      ;;
    *)
      _Dbg_undefined_cmd "set" "$set_cmd"
      return 1
  esac
}

# This is put at the so we have something at the end when we debug this.
typeset -r _Dbg_set_ver=\
'$Id: dbg-set.inc,v 1.11 2007/03/03 05:02:30 rockyb Exp $'

#;;; Local Variables: ***
#;;; mode:shell-script ***
#;;; End: ***
