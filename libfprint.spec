Name:           libfprint
Version:        1.94.7+tod1
Release:        1%{?dist}
Summary:        libfprint fork with external driver support

License:        LGPL
URL:            https://gitlab.freedesktop.org/3v1n0/libfprint/
Source0:        libfprint-%{version}.tar.gz

BuildRequires:  meson
BuildRequires:  gcc
BuildRequires:  gcc-c++
BuildRequires:  git
BuildRequires:  pkgconfig(glib-2.0) >= 2.50
BuildRequires:  pkgconfig(gio-2.0) >= 2.44.0
BuildRequires:  pkgconfig(gusb) >= 0.3.0
BuildRequires:  pkgconfig(nss)
BuildRequires:  pkgconfig(pixman-1)
BuildRequires:  gtk-doc
BuildRequires:  libgudev-devel
# For the udev.pc to install the rules
BuildRequires:  systemd
BuildRequires:  gobject-introspection-devel
# For internal CI tests; umockdev 0.13.2 has an important locking fix
BuildRequires:  python3-cairo python3-gobject cairo-devel
BuildRequires:  umockdev >= 0.13.2


%description


%package        devel
Summary:        Development files for %{name}
Requires:       %{name}%{?_isa} = %{version}-%{release}

%description    devel
The %{name}-devel package contains libraries and header files for
developing applications that use %{name}.

%global debug_package %{nil}
%prep
%autosetup

%build
%meson -Db_asneeded=false -Dinstalled-tests=false -Dtod=true -Dc_link_args='-Wl,-z,relro -Wl,--no-as-needed  -Wl,-z,pack-relative-relocs -Wl,-z,now -specs=/usr/lib/rpm/redhat/redhat-hardened-ld-errors -specs=/usr/lib/rpm/redhat/redhat-hardened-ld -specs=/usr/lib/rpm/redhat/redhat-annobin-cc1  -Wl,--build-id=sha1'
%meson_build

%install
%meson_install
mkdir -p %{buildroot}/usr/lib64/libfprint-2/tod-1

%files
%license COPYING
%doc NEWS THANKS AUTHORS README.md
%{_libdir}/*.so.*
%{_libdir}/girepository-1.0/*.typelib
%{_udevhwdbdir}/*.hwdb
%{_udevrulesdir}/*.rules

%files devel
%doc HACKING.md
%{_includedir}/*
%{_libdir}/*.so
%{_libdir}/pkgconfig/*%{name}*
%{_datadir}/gir-1.0/*.gir
%{_datadir}/gtk-doc/html/libfprint-2/


%changelog
* Mon Apr 22 2024 Craig Cabrey <craigcabrey@gmail.com> 1.94.7+tod1-1
- new package built with tito

* Fri Apr 19 2024 Craig Cabrey
- 
