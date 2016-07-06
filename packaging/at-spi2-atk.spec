%bcond_with x

Name: at-spi2-atk
Version: 2_12_0
Release: 1
Summary: Assistive Technology Service Provider Interface - GTK+ module
License: LGPL-2.0+
Group: System/Libraries
Url: http://www.gnome.org/
Source: http://download.gnome.org/sources/at-spi2-atk/2.12/%{name}-2.12.tar.xz
Source1001: %{name}.manifest
Requires: at-spi2-core
BuildRequires: dbus-devel
BuildRequires: glib2-devel
BuildRequires: atk-devel
BuildRequires: at-spi2-core-devel
BuildRequires: gettext
%if ! %{with x}
ExclusiveArch:
%endif

%description
AT-SPI is a general interface for applications to make use of the
accessibility toolkit. This version is based on dbus.

%package -n libatk-bridge-2_0-0
Summary: ATK/D-Bus bridging library
Group: System/Libraries

%description -n libatk-bridge-2_0-0
AT-SPI is a general interface for applications to make use of the
accessibility toolkit. This version is based on dbus.

The package contains a ATK/D-Bus bridge library.

%package devel
Summary: Assistive Technology Service Provider Interface - Developent files
Group: System/Libraries
Requires: libatk-bridge-2_0-0 = %{version}

%description devel
AT-SPI is a general interface for applications to make use of the
accessibility toolkit. This version is based on dbus.

%prep
%setup -q
cp %{SOURCE1001} .

%build
%autogen
%__make %{?_smp_flags}

%install
rm -rf %{buildroot}
%make_install
find %{buildroot} -name '*.la' -or -name '*.a' | xargs rm -f
find %{buildroot} -name '*.desktop' | xargs rm -f

%clean
rm -rf %{buildroot}

%post -n libatk-bridge-2_0-0 -p /sbin/ldconfig

%postun -n libatk-bridge-2_0-0 -p /sbin/ldconfig

%files -n libatk-bridge-2_0-0
%manifest %{name}.manifest
%defattr(-,root,root)
%{_libdir}/libatk-bridge-2.0.so.*
%{_libdir}/gtk-2.0/modules/libatk-bridge.so

%files devel
%manifest %{name}.manifest
%defattr(-,root,root)
%{_includedir}/at-spi2-atk/2.0/atk-bridge.h
%{_libdir}/libatk-bridge-2.0.so
%{_libdir}/pkgconfig/atk-bridge-2.0.pc

%changelog
* Mon Mar 25 2013 tomasz.duszynski@comarch.com
- Initial packaging of at-spi2-atk (2.5.92)

