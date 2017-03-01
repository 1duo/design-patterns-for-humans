class President:
    instance = None

    @classmethod
    def get_instance(cls):
        if not cls.instance:
            cls.instance = President()
        return cls.instance


if __name__ == '__main__':

    president1 = President().get_instance()
    president2 = President().get_instance()
    assert president1 is president2
