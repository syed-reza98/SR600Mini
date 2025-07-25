use strict;
use warnings;
package Software::License::Zlib;
BEGIN {
  $Software::License::Zlib::VERSION = '0.102340';
}
use base 'Software::License';
# ABSTRACT: The zlib License

sub name { 'The zlib License' }
sub url  { 'http://www.zlib.net/zlib_license.html' }

sub meta_name  { 'open_source' }
sub meta2_name { 'zlib' }

1;


=pod

=head1 NAME

Software::License::Zlib - The zlib License

=head1 VERSION

version 0.102340

=head1 AUTHOR

Ricardo Signes <rjbs@cpan.org>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2010 by Ricardo Signes.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut


__DATA__
__LICENSE__
The zlib License

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must
     not claim that you wrote the original software. If you use this
     software in a product, an acknowledgment in the product
     documentation would be appreciated but is not required.

  2. Altered source versions must be plainly marked as such, and must
     not be misrepresented as being the original software.

  3. This notice may not be removed or altered from any source
     distribution.
