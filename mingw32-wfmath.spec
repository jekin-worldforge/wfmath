%define __strip %{_mingw32_strip}
%define __objdump %{_mingw32_objdump}
%define _use_internal_dependency_generator 0
%define __find_requires %{_mingw32_findrequires}
%define __find_provides %{_mingw32_findprovides}

%define name mingw32-wfmath
%define version 0.3.11
%define release 1
%define libsuffix -0.3

Summary: A math library.
Name: %{name}
Version: %{version}
Release: %{release}
License: GPL
Group: System Environment/Libraries
URL: http://www.worldforge.org/dev/eng/libraries/wfmath
Packager: Al Riddoch <alriddoch@googlemail.com>
Vendor: WorldForge
Distribution: Mason
Source: wfmath-%{version}.tar.bz2
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root
BuildArch: noarch
BuildRequires:  mingw32-filesystem >= 49
BuildRequires:  mingw32-gcc
BuildRequires:  mingw32-binutils

%description
This is the WorldForge math library. The primary focus of wfmath is
geometric objects.

%prep
%setup -q -n wfmath-%{version}

%build
%{_mingw32_configure} --enable-static --disable-shared
make

%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install
rm $RPM_BUILD_ROOT%{_mingw32_libdir}/lib*.la


%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%{_mingw32_libdir}/lib*.a
%{_mingw32_libdir}/pkgconfig/*
%{_mingw32_includedir}/wfmath%{libsuffix}
%doc AUTHORS COPYING NEWS README
