class Builder:

    def build(self):
        self.test()
        self.lint()
        self.assemble()
        self.deploy()

    def test(self):
        raise NotImplementedError

    def lint(self):
        raise NotImplementedError

    def assemble(self):
        raise NotImplementedError

    def deploy(self):
        raise NotImplementedError


class AndroidBuilder(Builder):

    def test(self):
        print('Running Android tests')

    def lint(self):
        print('Linting the Android code')

    def assemble(self):
        print('Assembling the Android build')

    def deploy(self):
        print('Deploying Android build to server')


class IosBuilder(Builder):

    def test(self):
        print('Running iOS tests')

    def lint(self):
        print('Linting the iOS code')

    def assemble(self):
        print('Assembling the iOS build')

    def deploy(self):
        print('Deploying iOS build to server')


if __name__ == '__main__':

    android_builder = AndroidBuilder()
    android_builder.build()
    # output:
    # Running Android tests
    # Linting the Android code
    # Assembling the Android build
    # Deploying Android build to server

    ios_builder = IosBuilder()
    ios_builder.build()
    # output:
    # Running iOS tests
    # Linting the iOS code
    # Assembling the iOS build
    # Deploying iOS build to server
