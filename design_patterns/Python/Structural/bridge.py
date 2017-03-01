class WebPage:

    def get_content(self):
        raise NotImplementedError


class About(WebPage):

    def __init__(self, theme):
        self.theme = theme

    def get_content(self):
        return 'About page in ' + self.theme.get_color()


class Careers(WebPage):

    def __init__(self, theme):
        self.theme = theme

    def get_content(self):
        return 'Careers page in ' + self.theme.get_color()


class Theme:

    def get_color(self):
        pass


class DarkTheme(Theme):

    def get_color(self):
        return 'Dark Black'


class LightTheme(Theme):

    def get_color(self):
        return 'Off White'


class AquaTheme(Theme):

    def get_color(self):
        return 'Light Blue'


if __name__ == '__main__':

    dark_theme = DarkTheme()
    about = About(dark_theme)
    careers = Careers(dark_theme)
    assert about.get_content() == 'About page in Dark Black'
    assert careers.get_content() == 'Careers page in Dark Black'
