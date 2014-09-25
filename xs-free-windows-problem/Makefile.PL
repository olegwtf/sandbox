use ExtUtils::MakeMaker;
use Config;

my @additional;
if ($^O eq 'MSWin32') {
	push @additional, INC    => '-Ipthreads-win32/include';
	push @additional, DEFINE => '-D_WIN32_WINNT=0x0501 -DPTW32_STATIC_LIB';
	my ($arch) = $Config{archname} =~ /mswin32-([^-]+)/i;
	push @additional, LIBS   => [":nosearch -Lpthreads-win32/lib/$arch -lpthread -lWS2_32"];
}

WriteMakefile(
	NAME           => 'My',
	VERSION_FROM   => 'lib/My.pm',
	LIBS           => ['-lpthread'],
	@additional
);
