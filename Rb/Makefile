
.DEFAULT: all
all: ruby-dist/lib/libruby-static.a

DIST = ruby-1.9.2-p180

DL = ftp://ftp.ruby-lang.org//pub/ruby/1.9/$(DIST).tar.gz

WGET=$(shell which wget 2>/dev/null)

ruby-dist/lib/libruby-static.a: $(DIST)/libruby-static.a
	$(MAKE) -C $(DIST) install
	cd ruby-dist/include/ruby-1.9.1/ruby && ln -s ../*/ruby/config.h config.h

$(DIST)/libruby-static.a: $(DIST)/Makefile
	$(MAKE) -j -C $(DIST)

$(DIST)/Makefile: $(DIST)/configure
	cd $(DIST) && ./configure --prefix=$(CURDIR)/ruby-dist --disable-install-doc

$(DIST)/configure: $(DIST).tar.gz
	rm -rf $(DIST)
	tar xzf $<
	touch $@

$(DIST).tar.gz:
	@if [ -z "$(WGET)" ] ; then \
		echo "Please install wget or download $(DL) manually."; \
		exit 1; \
	fi
	$(WGET) $(DL)
