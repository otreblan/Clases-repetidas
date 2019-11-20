# Maintainer: Otreblan <otreblain@gmail.com>

pkgname=spaceclones-git
pkgver=r11.2e85620
pkgrel=1
epoch=
pkgdesc="Clon de Space invaders"
arch=('x86_64')
url="https://github.com/L603/SpaceClones"
license=('GPL3')
groups=()
depends=('sfml')
makedepends=('git' 'cmake')
checkdepends=()
optdepends=()
provides=('spaceclones')
conflicts=('spaceclones')
source=("${pkgname}::git+${url}.git")
md5sums=('SKIP')

prepare() {
	mkdir -p "${pkgname}/build"
}

pkgver() {
	cd "$srcdir/$pkgname"
	( set -o pipefail
	git describe --long 2>/dev/null | sed 's/^v-//;s/\([^-]*-g\)/r\1/;s/-/./g' ||
	printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
	)
}

build() {
	cd "${pkgname}/build" || exit 1
	cmake -DCMAKE_INSTALL_PREFIX=/usr ..
	make
}

package() {
	cd "${pkgname}/build" || exit 1
	make DESTDIR="$pkgdir/" install
}
